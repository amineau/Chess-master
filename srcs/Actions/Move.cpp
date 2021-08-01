/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:29:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actions/Move.hpp"
#include "Components/Pieces/Piece.hpp"
#include "Components/Spot.hpp"
#include "Game/GameStatus.hpp"

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
	this->generateRepr();
}

void Move::addStatusChar(const char status)
{
	this->_repr += status;
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
