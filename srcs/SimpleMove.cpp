/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleMove.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:50:51 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 21:17:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimpleMove.hpp"

SimpleMove::SimpleMove()
	: Move()
{
	return;
}

SimpleMove::SimpleMove(GameStatus* gameStatus, Player* player, Spot* start, Spot* end)
	: Move(gameStatus, player, start, end)
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
	return this->_pieceMoved->getType() == PAWN && abs(this->_end->getY() - this->_start->getY()) == 2;
}

bool SimpleMove::isLegal() const
{
	return !this->_pieceMoved
		|| this->_pieceMoved->isWhite() != this->_player->isWhite()
		|| this->_player != this->_gameStatus->getCurrentTurn()
		|| this->_pieceMoved->canMoves(this->_gameStatus, this->_start, this->_end);
}

void SimpleMove::execute()
{
	if (this->_pieceKilled)
		this->_pieceKilled->killed();
	this->_end->setPiece(this->_pieceMoved);
	this->_start->setPiece(0);
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);
	if (this->isDoublePushPawn()) {
		if (this->_player->isWhite())
			this->_gameStatus->setEnPassantTargetSpot(
				this->_gameStatus->getBox(this->_start->getX(), 2));
		else
			this->_gameStatus->setEnPassantTargetSpot(
				this->_gameStatus->getBox(this->_start->getX(), 5));
	} else
		this->_gameStatus->setEnPassantTargetSpot(0);
	if (this->_pieceMoved->getType() == PAWN || !this->_pieceKilled)
		this->_gameStatus->incrementHalfMoveClock();
}

const std::string SimpleMove::getRepr() const
{
	std::stringstream ss;

	ss << *this->_start << (this->_pieceKilled ? 'x' : '-') << *this->_end;
	return ss.str();
}