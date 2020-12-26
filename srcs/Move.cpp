/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:10:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Move.hpp"

Move::Move()
{
	return;
}

Move::Move(Player* player, Spot* start, Spot* end)
	: _player(player)
	, _start(start)
	, _end(end)
	, _pieceMoved(start->getPiece())
	, _pieceKilled(end->getPiece())
{
	return;
}

Move::Move(Move const& src)
{
	*this = src;
	return;
}

Move::~Move()
{
	return;
}

/* Accessors */

Player const* Move::getPlayer() const
{
	return this->_player;
}

Spot const* Move::getStartSpot() const
{
	return this->_start;
}

Spot const* Move::getEndSpot() const
{
	return this->_end;
}

Piece const* Move::getPieceMoved() const
{
	return this->_pieceMoved;
}

Piece const* Move::getPieceKilled() const
{
	return this->_pieceKilled;
}

/* Members functions */

/* Operators Overload */

Move& Move::operator=(Move const& rhs)
{
	if (this != &rhs) {
		this->_player = rhs._player;
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_pieceMoved = rhs._pieceMoved;
		this->_pieceKilled = rhs._pieceKilled;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Move const& i)
{
	o << i.getPieceMoved() << i.getEndSpot() << std::endl;
	return o;
}