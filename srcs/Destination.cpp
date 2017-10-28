/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Destination.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2017/10/25 22:54:21 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Destination.hpp"

Destination::Destination(size_t x, size_t y, APiece * player, APiece * target)
	: x(x)
	, y(y)
	, _target(target)
	, _player(player)
{
	if (this->x > BOARD_MAX || this->y > BOARD_MAX)
		throw Destination::DestinationOutSidePositionException();
}

Destination::Destination(size_t x, size_t y, APiece * player)
	: x(x)
	, y(y)
	, _target(NULL)
	, _player(player)
{
	if (this->x > BOARD_MAX || this->y > BOARD_MAX)
		throw Destination::DestinationOutSidePositionException();
}

Destination::Destination( Destination const & src )
{
	*this = src;
	return;
}

Destination::~Destination() {
	return;
}

APiece *		Destination::getTarget() const {
	return this->_target;
}

APiece *		Destination::getPlayer() const {
	return this->_player;
}


Destination &	Destination::operator=( Destination const & rhs ) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
		this->_player = rhs._player;
		this->_target = rhs._target;
	}
	return *this;
}

/* Operator Overload */

std::ostream &	operator<<( std::ostream & o, Destination const & i ) {
	if (i.getPlayer()->getType() == KING
		&& i.x == i.getPlayer()->getX() + 2) {
		o << "O-O";
		return o;
	}
	if (i.getPlayer()->getType() == KING
		&& i.x == i.getPlayer()->getX() + 2) {
		o << "O-O-O";
		return o;
	}
	if (i.getPlayer()->getType() != PAWN)
		o << *i.getPlayer();
	if (i.getTarget()) {
		if (i.getPlayer()->getType() == PAWN)
			o << i.getPlayer()->getXRepresentation();
		o << "x";
	}
	o << static_cast<char>(i.x + 'a') << i.y + 1;
	if (i.getPlayer()->getType() == PAWN
		&& i.getTarget() && i.getTarget()->getX() == i.getPlayer()->getX())
		o << "e.p.";
	return o;
}

/* Exception */

char const *	Destination::DestinationOutSidePositionException::what() const throw() {
	return "Position is outside";
}
