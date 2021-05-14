/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleMove.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:50:51 by amineau           #+#    #+#             */
/*   Updated: 2021/05/14 23:38:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimpleMove.hpp"

SimpleMove::SimpleMove()
	: Move()
{
	return;
}

SimpleMove::SimpleMove(GameStatus* gameStatus, Spot* start, Spot* end)
	: Move(gameStatus, start, end)
{
	return;
}

SimpleMove::SimpleMove(SimpleMove const& src)
	: Move()
{
	*this = src;
	return;
}

SimpleMove::~SimpleMove()
{
	return;
}

SimpleMove& SimpleMove::operator=(SimpleMove const& rhs)
{
	if (this != &rhs) {
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_pieceMoved = rhs._pieceMoved;
		this->_pieceKilled = rhs._pieceKilled;
	}
	return *this;
}

bool SimpleMove::isDoublePushPawn() const
{
	return this->_pieceMoved->getType() == PAWN && abs(static_cast<int>(this->_end->getY() - this->_start->getY())) == 2;
}

bool SimpleMove::isLegal() const
{
	return this->_pieceMoved
		&& this->_pieceMoved->isWhite() == this->_isWhitePlayer
		&& this->_pieceMoved->canMoves(this->_gameStatus, this->_start, this->_end);
}

bool SimpleMove::execute()
{
	if (!isLegal())
		return false;
	if (this->_pieceKilled)
		this->_pieceKilled->killed();
	this->_end->setPiece(this->_pieceMoved);
	this->_start->setPiece(0);
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);
	if (this->isDoublePushPawn()) {
		if (this->_isWhitePlayer)
			this->_gameStatus->setEnPassantTargetSpot(
				this->_gameStatus->getSpot(this->_start->getX(), 2));
		else
			this->_gameStatus->setEnPassantTargetSpot(
				this->_gameStatus->getSpot(this->_start->getX(), 5));
	} else
		this->_gameStatus->setEnPassantTargetSpot(0);
	if (this->_pieceMoved->getType() != PAWN || !this->_pieceKilled)
		this->_gameStatus->incrementHalfMoveClock();
	else
		this->_gameStatus->resetHalfMoveClock();
	this->setCastlings();
	this->_gameStatus->updateStatus();
	return true;
}

void SimpleMove::setCastlings()
{
	if (this->_gameStatus->getKingSideCastlingAvailable(this->_isWhitePlayer)
		&& (this->_pieceMoved->getType() == KING
			|| (this->_pieceMoved->getType() == ROOK
				&& this->_start->getX() == 7
				&& this->_start->getY() == (this->_isWhitePlayer ? 0 : 7)))) {
		this->_gameStatus->setKingSideCastlingAvailable(false, this->_isWhitePlayer);
	}
	if (this->_gameStatus->getQueenSideCastlingAvailable(this->_isWhitePlayer)
		&& (this->_pieceMoved->getType() == KING
			|| (this->_pieceMoved->getType() == ROOK
				&& this->_start->getX() == 0
				&& this->_start->getY() == (this->_isWhitePlayer ? 0 : 7)))) {
		this->_gameStatus->setQueenSideCastlingAvailable(false, this->_isWhitePlayer);
	}
}

SimpleMove* SimpleMove::clone() const
{
	return new SimpleMove(*this);
}

const std::string SimpleMove::getRepr() const
{
	std::stringstream ss;

	ss << *this->_start << (this->_pieceKilled ? 'x' : '-') << *this->_end;
	return ss.str();
}