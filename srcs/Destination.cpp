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

/* Exception */

char const *	Destination::DestinationOutSidePositionException::what() const throw() {
	return "Position is outside";
}
