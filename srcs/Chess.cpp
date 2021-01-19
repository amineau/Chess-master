/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chess.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2021/01/20 00:14:30 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Chess.hpp"
#include "Bishop.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

Chess::Chess()
	: _board(NULL)
	, _playerWhite(new Player(true))
	, _playerBlack(new Player(false))
{
	return;
}

Chess::Chess(Chess const& src)
{
	*this = src;
	return;
}

Chess::~Chess()
{
	delete this->_playerWhite;
	delete this->_playerBlack;
	// delete this->_board;
	return;
}

Chess& Chess::operator=(Chess const& rhs)
{
	if (this != &rhs) {
		this->_board = rhs._board;
		this->_currentTurn = rhs._currentTurn;
		this->_playerWhite = rhs._playerWhite;
		this->_playerBlack = rhs._playerBlack;
		this->_movesPlayed = rhs._movesPlayed;
	}
	return *this;
}

/* Accessors */

Board* Chess::getBoard() const
{
	// if (!this->_board)
	// throw exception;
	return this->_board;
}

Spot* Chess::getBox(const std::string& pos) const
{
	return this->getBoard()->getBox(pos);
}
Piece* Chess::getPiece(const std::string& pos) const
{
	return this->getBox(pos)->getPiece();
}

std::vector<Move> Chess::getMovesPlayed() const
{
	return this->_movesPlayed;
}

Player* Chess::getCurrentTurn() const
{
	return this->_currentTurn;
}

void Chess::setCurrentTurn(Player* player)
{
	this->_currentTurn = player;
}

Player* Chess::getPlayerWhite() const
{
	return this->_playerWhite;
}

Player* Chess::getPlayerBlack() const
{
	return this->_playerBlack;
}

/* Members functions */

bool Chess::playerMoved(Player* player, const std::string& start, const std::string& end)
{
	Move move = Move(player, this->_board->getBox(start), this->_board->getBox(end));
	return this->makeMove(player, move);
}

bool Chess::makeMove(Player* player, Move move)
{
	Piece* piece = move.getPieceMoved();
	Piece* pieceKilled = move.getPieceKilled();
	if (!piece || piece->isWhite() != player->isWhite() || player != this->_currentTurn)
		return false;
	if (!piece->canMoves(this->_board, move.getStartSpot(), move.getEndSpot()))
		return false;
	if (pieceKilled)
		pieceKilled->killed();
	move.getEndSpot()->setPiece(piece);
	move.getStartSpot()->setPiece(NULL);
	this->_currentTurn = this->_currentTurn->isWhite() ? this->_playerBlack : this->_playerWhite;
	this->_movesPlayed.push_back(move);
	return true;
}

const std::string Chess::fen() const
{
	std::stringstream ss;

	ss << this->_fenBoard() << ' '
	   << this->_fenCurrentPlayer() << ' '
	   << this->_fenCastlingsAvailable() << ' '
	   << this->_fenEnPassantTargetSpot() << ' '
	   << this->_fenHalfMoveClock() << ' '
	   << this->_fenFullMoveCounter();
	return ss.str();
}

bool Chess::load_fen(const std::string& fen)
{
	const std::vector<std::string> fenSplit = split(fen, ' ');

	delete this->_board;
	this->_board = new Board();

	return (fenSplit.size() == 6
		&& this->_loadFenBoard(fenSplit[0])
		&& this->_loadFenCurrentPlayer(fenSplit[1])
		&& this->_loadFenCastlingsAvailable(fenSplit[2])
		&& this->_loadFenEnPassantTargetSpot(fenSplit[3])
		&& this->_loadFenHalfMoveClock(fenSplit[4])
		&& this->_loadFenFullMoveCounter(fenSplit[5]));
}

bool Chess::_loadFenBoard(const std::string& str)
{
	return this->_board->load_fen(str);
}

bool Chess::_loadFenCurrentPlayer(const std::string& str)
{
	if (!str.compare("w"))
		this->setCurrentTurn(this->getPlayerWhite());
	else if (!str.compare("b"))
		this->setCurrentTurn(this->getPlayerBlack());
	else
		return false;
	return true;
}
bool Chess::_loadFenCastlingsAvailable(const std::string& str)
{
	short index = 0;

	this->_castlingKingBlackAvailable = false;
	this->_castlingKingWhiteAvailable = false;
	this->_castlingQueenBlackAvailable = false;
	this->_castlingQueenWhiteAvailable = false;

	if (str[index] && str[index] == 'K') {
		this->_castlingKingWhiteAvailable = true;
		index++;
	}
	if (str[index] && str[index] == 'Q') {
		this->_castlingQueenWhiteAvailable = true;
		index++;
	}
	if (str[index] && str[index] == 'k') {
		this->_castlingKingBlackAvailable = true;
		index++;
	}
	if (str[index] && str[index] == 'q') {
		this->_castlingQueenBlackAvailable = true;
		index++;
	}
	return (!str[index] || !str.compare("-"));
}
bool Chess::_loadFenEnPassantTargetSpot(const std::string& str)
{
	return (((this->_enPassantTargetSpot = this->_board->getBox(str)) && (str[1] == '3' || str[1] == '6'))
		|| !str.compare("-"));
}
bool Chess::_loadFenHalfMoveClock(const std::string& str)
{
	if (!isNumber(str))
		return false;
	this->_halfMoveClock = stoi(str);
	return true;
}
bool Chess::_loadFenFullMoveCounter(const std::string& str)
{
	if (!isNumber(str))
		return false;
	this->_fullMoveCounter = stoi(str);
	return true;
}

const std::string Chess::_fenBoard() const
{
	return this->_board->fen();
}

const std::string Chess::_fenCurrentPlayer() const
{
	return this->_currentTurn->isWhite() ? "w" : "b";
}
const std::string Chess::_fenCastlingsAvailable() const
{
	std::string str = "";
	if (this->_castlingKingWhiteAvailable)
		str += 'K';
	if (this->_castlingQueenWhiteAvailable)
		str += 'Q';
	if (this->_castlingKingBlackAvailable)
		str += 'k';
	if (this->_castlingQueenBlackAvailable)
		str += 'q';
	if (str.empty())
		str = "-";
	return str;
}
const std::string Chess::_fenEnPassantTargetSpot() const
{
	if (this->_enPassantTargetSpot)
		return this->_enPassantTargetSpot->getRepr();
	else
		return "-";
}
const std::string Chess::_fenHalfMoveClock() const
{
	return std::to_string(this->_halfMoveClock);
}
const std::string Chess::_fenFullMoveCounter() const
{
	return std::to_string(this->_fullMoveCounter);
}