/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastlingMove.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:50:51 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 21:17:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CastlingMove.hpp"
#include "King.hpp"

CastlingMove::CastlingMove()
	: Move()
{
	return;
}

CastlingMove::CastlingMove(GameStatus* gameStatus, Player* player, Spot* start, Spot* end)
	: Move(gameStatus, player, start, end)
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
		&& king->isWhite() == this->_player->isWhite()
		&& this->_player == this->_gameStatus->getCurrentPlayer()
		&& (king->canKingSideCastlingMoves(this->_gameStatus, this->_start, this->_end)
			|| king->canQueenSideCastlingMoves(this->_gameStatus, this->_start, this->_end));
}

void CastlingMove::execute()
{
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

	this->_end->setPiece(this->_pieceMoved);
	this->_start->setPiece(0);

	endSpotRook->setPiece(startSpotRook->getPiece());
	startSpotRook->setPiece(0);

	this->_gameStatus->setKingSideCastlingAvailable(false, this->_player->isWhite());
	this->_gameStatus->setQueenSideCastlingAvailable(false, this->_player->isWhite());
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);
	this->_gameStatus->setEnPassantTargetSpot(0);
	this->_gameStatus->incrementHalfMoveClock();
}

CastlingMove* CastlingMove::clone() const
{
	return new CastlingMove(*this);
}

const std::string CastlingMove::getRepr() const
{
	std::stringstream ss;

	ss << *this->_start << (this->_pieceKilled ? 'x' : '-') << *this->_end;
	return ss.str();
}