/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2021/05/23 16:23:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Move.hpp"
#include "GameStatus.hpp"
#include "Piece.hpp"
#include "Spot.hpp"

Move::Move()
	: Action()
{
	return;
}

Move::Move(GameStatus* gameStatus, Spot* start, Spot* end)
	: Action(gameStatus)
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

/* Members functions */

void Move::executeMove()
{
	if (this->_pieceKilled)
		this->_gameStatus->getBoard()->removePiece(this->_pieceKilled);
	this->_end->setPiece(this->_pieceMoved);
	this->_start->setPiece(0);
}

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