/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2020/12/28 18:24:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Spot.hpp"
#include "Piece.hpp"

Spot::Spot()
{
	return;
}

Spot::Spot(size_t x, size_t y)
	: _x(x)
	, _y(y)
	, _piece(NULL)
{
	return;
}

Spot::Spot(size_t x, size_t y, Piece* piece)
	: _x(x)
	, _y(y)
	, _piece(piece)
{
	return;
}

Spot::Spot(Spot const& src)
{
	*this = src;
	return;
}

Spot::~Spot()
{
	return;
}

size_t Spot::getX() const
{
	return this->_x;
}

size_t Spot::getY() const
{
	return this->_y;
}

Piece* Spot::getPiece() const
{
	return this->_piece;
}

void Spot::setPiece(Piece* piece)
{
	this->_piece = piece;
}

/* Operators Overload */

Spot& Spot::operator=(Spot const& rhs)
{
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_piece = rhs._piece;
	}
	return *this;
}

bool Spot::operator==(Spot const& rhs) const
{
	return (this == &rhs || (this->_x == rhs._x && this->_y == rhs._y));
}

std::ostream& operator<<(std::ostream& o, Spot const& i)
{
	o << static_cast<char>(i.getX() + 'a') << i.getY() << std::endl;
	return o;
}