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
	: _status(INPROGRESS)
	, _playerWhite(Player(true))
	, _playerBlack(Player(false))
{
	// std::cout << "Chess CONSTRUCTOR" << std::endl;
	this->_gameStatus = new GameStatus(this->_playerWhite, this->_playerBlack);
	return;
}

Chess::Chess(Chess const& src)
{
	// std::cout << "Chess CONSTRUCTOR BY REF" << std::endl;
	*this = src;
	return;
}

Chess::~Chess()
{
	// std::cout << "Chess DECONSTRUCTOR" << std::endl;
	delete this->_gameStatus;
	return;
}

Chess& Chess::operator=(Chess const& rhs)
{
	if (this != &rhs) {
		this->_status = rhs._status;
		this->_playerWhite = rhs._playerWhite;
		this->_playerBlack = rhs._playerBlack;
		*(this->_gameStatus) = *(rhs._gameStatus);
	}
	return *this;
}

/* Accessors */

/* Members functions */

std::vector<Spot*> Chess::validSpots(const std::string& pos) const
{
	Spot*			   spot = _gameStatus->getSpot(pos);
	Piece*			   piece = _gameStatus->getPiece(pos);
	std::vector<Spot*> validSpots;

	if (piece && piece->isWhite() == this->getCurrentPlayer()->isWhite())
		validSpots = piece->validSpots(_gameStatus, spot);
	return validSpots;
}

std::vector<Spot*> Chess::validSpots(size_t x, size_t y) const
{
	Spot*			   spot = _gameStatus->getSpot(x, y);
	Piece*			   piece = _gameStatus->getPiece(x, y);
	std::vector<Spot*> validSpots;

	if (piece && piece->isWhite() == this->getCurrentPlayer()->isWhite())
		validSpots = piece->validSpots(_gameStatus, spot);
	return validSpots;
}

Move* Chess::getMoveAction(const std::string& start, const std::string& end) const
{
	Spot* startSpot = this->_gameStatus->getSpot(start);
	Spot* endSpot = this->_gameStatus->getSpot(end);

	if (startSpot->getPiece()
		&& startSpot->getPiece()->getType() == PAWN
		&& endSpot == this->_gameStatus->getEnPassantTargetSpot())
		return new EnPassantMove(this->_gameStatus, startSpot, endSpot);
	if (startSpot->getPiece()
		&& startSpot->getPiece()->getType() == KING
		&& abs(static_cast<int>(startSpot->getX() - endSpot->getX())) == 2)
		return new CastlingMove(this->_gameStatus, startSpot, endSpot);
	return new SimpleMove(this->_gameStatus, startSpot, endSpot);
}

void Chess::updateStatus()
{
	bool isWhite = this->_gameStatus->getCurrentPlayer()->isWhite();
	bool isCheck = this->_gameStatus->isCheck(isWhite);

	if (this->_gameStatus->hasNoMovePossible(isWhite)) {
		if (isCheck)
			this->_status = CHECKMATE;
		else
			this->_status = DRAW;
	} else if (this->_gameStatus->getHalfMoveClock() >= 50) {
		this->_status = STALEMATE;
	}
}

bool Chess::makeAction(Action* action)
{
	bool result = action->execute();
	if (result)
		this->updateStatus();
	return result;
}

bool Chess::load(const std::string& fen)
{
	bool result = Loader(this->_gameStatus).fen(fen);
	if (result)
		this->updateStatus();
	return result;
}

const std::string Chess::fen() const
{
	return Exporter(this->_gameStatus).fen();
}