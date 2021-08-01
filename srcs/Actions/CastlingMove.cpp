/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastlingMove.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:50:51 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:28:47 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actions/CastlingMove.hpp"
#include "Components/Pieces/King.hpp"

CastlingMove::CastlingMove()
	: Move()
{
	return;
}

CastlingMove::CastlingMove(GameStatus* gameStatus, Spot* start, Spot* end)
	: Move(gameStatus, start, end)
{
	return;
}

CastlingMove::CastlingMove(CastlingMove const& src)
	: Move()
{
	*this = src;
	return;
}

CastlingMove::~CastlingMove()
{
	return;
}

CastlingMove& CastlingMove::operator=(CastlingMove const& rhs)
{
	if (this != &rhs) {
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_pieceMoved = rhs._pieceMoved;
		this->_pieceKilled = rhs._pieceKilled;
	}
	return *this;
}

bool CastlingMove::isLegal() const
{
	King* king = dynamic_cast<King*>(this->_pieceMoved);

	return king
		&& king->isWhite() == this->_isWhitePlayer
		&& (king->canKingSideCastlingMoves(this->_gameStatus, this->_start, this->_end)
			|| king->canQueenSideCastlingMoves(this->_gameStatus, this->_start, this->_end));
}

bool CastlingMove::execute()
{
	if (!isLegal())
		return false;

	bool  isKingSide = (this->_end->getX() == 6);
	Spot* startSpotRook;
	Spot* endSpotRook;

	if (isKingSide) {
		startSpotRook = this->_gameStatus->getSpot(7, this->_end->getY());
		endSpotRook = this->_gameStatus->getSpot(5, this->_end->getY());
	} else {
		startSpotRook = this->_gameStatus->getSpot(0, this->_end->getY());
		endSpotRook = this->_gameStatus->getSpot(3, this->_end->getY());
	}

	this->executeMove();

	endSpotRook->setPiece(startSpotRook->getPiece());
	startSpotRook->setPiece(0);

	this->_gameStatus->setKingSideCastlingAvailable(false, this->_isWhitePlayer);
	this->_gameStatus->setQueenSideCastlingAvailable(false, this->_isWhitePlayer);
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);
	this->_gameStatus->setEnPassantTargetSpot(0);
	this->_gameStatus->incrementHalfMoveClock();
	return true;
}

CastlingMove* CastlingMove::clone() const
{
	return new CastlingMove(*this);
}

void CastlingMove::generateRepr()
{
	bool isKingSide = (this->_end->getX() == 6);

	this->_repr = isKingSide ? "O-O" : "O-O-O";
}