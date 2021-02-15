/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2021/01/27 19:24:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Move.hpp"

Move::Move()
	: Action()
{
	return;
}

Move::Move(GameStatus* gameStatus, Player* player, Spot* start, Spot* end)
	: Action(gameStatus, player)
	, _start(start)
	, _end(end)
{
	this->_pieceMoved = this->_start->getPiece();
	this->_pieceKilled = this->_end->getPiece();
	return;
}

Move::Move(Move const& src)
	: Action(src)
{
	*this = src;
	return;
}

Move::~Move()
{
	return;
}

/* Accessors */

Spot* Move::getStartSpot() const
{
	return this->_start;
}

Spot* Move::getEndSpot() const
{
	return this->_end;
}

Piece* Move::getPieceMoved() const
{
	return this->_pieceMoved;
}

Piece* Move::getPieceKilled() const
{
	return this->_pieceKilled;
}

/* Members functions */

/* Operators Overload */

Move& Move::operator=(Move const& rhs)
{
	if (this != &rhs) {
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_pieceMoved = rhs._pieceMoved;
		this->_pieceKilled = rhs._pieceKilled;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Move const& i)
{
	o << i.getRepr();
	return o;
}