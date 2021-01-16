/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 01:16:15 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Bishop.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

Game::Game()
{
	return;
}

Game::Game(Game const& src)
{
	*this = src;
	return;
}

Game::~Game()
{
	return;
}

Game& Game::operator=(Game const& rhs)
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

Board* Game::getBoard() const
{
	return this->_board;
}

void Game::setBoard(Board* board)
{
	this->_board = board;
}

std::vector<Move> Game::getMovesPlayed() const
{
	return this->_movesPlayed;
}

Player* Game::getCurrentTurn() const
{
	return this->_currentTurn;
}

void Game::setCurrentTurn(Player* player)
{
	this->_currentTurn = player;
}

Player* Game::getPlayerWhite() const
{
	return this->_playerWhite;
}

Player* Game::getPlayerBlack() const
{
	return this->_playerBlack;
}

/* Members functions */

bool Game::playerMoved(Player* player, size_t startX, size_t startY, size_t endX, size_t endY)
{
	Move move = Move(player, this->_board->getBox(startX, startY), this->_board->getBox(endX, endY));
	return this->makeMove(player, move);
}

bool Game::makeMove(Player* player, Move move)
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

void Game::load(const char* file)
{
	std::ifstream infile(file);
	this->_playerWhite = new Player(true);
	this->_playerBlack = new Player(false);

	infile >> *this;
}

std::istream& operator>>(std::istream& is, Game& game)
{
	std::string line;
	Board*		board = new Board();
	int			lineNumber = 0;
	Piece*		piece;

	while (lineNumber <= 16 && std::getline(is, line)) {
		if ((line.length() != 8 && lineNumber != 8)
			|| (lineNumber == 8 && line.length() != 0))
			throw Game::ParsingFileException(lineNumber);
		if (lineNumber < 8)
			for (int x = 0; x < 8; x++) {
				if (line[x] == '.')
					board->setBox(x, 7 - lineNumber, new Spot(x, 7 - lineNumber));
				else {
					switch (line[x]) {
					case 'K':
						piece = new King();
						break;
					case 'Q':
						piece = new Queen();
						break;
					case 'B':
						piece = new Bishop();
						break;
					case 'N':
						piece = new Knight();
						break;
					case 'R':
						piece = new Rook();
						break;
					case 'P':
						piece = new Pawn();
						break;
					default:
						throw Game::ParsingFileException(lineNumber, x);
					}
					board->setBox(x, 7 - lineNumber, new Spot(x, 7 - lineNumber, piece));
				}
			}
		else if (lineNumber > 8)
			for (int x = 0; x < 8; x++) {
				piece = board->getBox(x, 16 - lineNumber)->getPiece();
				if ((line[x] == '.' && piece)
					|| ((line[x] == 'W' || line[x] == 'B') && !piece)
					|| (line[x] != '.' && line[x] != 'W' && line[x] != 'B'))
					throw Game::ParsingFileException(lineNumber, x);
				if (line[x] == 'B')
					piece->setIsWhite(false);
				else if (line[x] == 'W')
					piece->setIsWhite(true);
			}
		lineNumber++;
	}
	board->raiseOnInvalidKingNumber();
	game.setBoard(board);
	if (std::getline(is, line) && line.length() != 0)
		throw Game::ParsingFileException(lineNumber);
	lineNumber++;
	if (std::getline(is, line)) {
		if (line.compare("W") == 0)
			game.setCurrentTurn(game.getPlayerWhite());
		else if (line.compare("B") == 0)
			game.setCurrentTurn(game.getPlayerBlack());
		else
			throw Game::ParsingFileException(lineNumber);
	} else
		throw Game::ParsingFileException(lineNumber);

	return is;
}

Game::ParsingFileException::ParsingFileException(size_t line) throw()
{
	this->_message = "Parsing failed at line " + std::to_string(line);
}

Game::ParsingFileException::ParsingFileException(size_t line, size_t column) throw()
{
	this->_message = "Parsing failed at line " + std::to_string(line) + " and column " + std::to_string(column);
}

char const* Game::ParsingFileException::what() const throw()
{
	return this->_message.c_str();
}