/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 23:51:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Spot.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

Spot::Spot()
{
	return;
}

Spot::Spot(size_t x, size_t y)
	: _x(x)
	, _y(y)
	, _piece(0)
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
	// delete this->_piece;
	return;
}

/* Operators Overload */

Spot& Spot::operator=(Spot const& rhs)
{
	if (this != &rhs) {
		this->_x = rhs._x;
		this->_y = rhs._y;
		if (rhs._piece) {
			if (rhs._piece->getType() == KING)
				this->_piece = new King(*dynamic_cast<King*>(rhs._piece));
			else if (rhs._piece->getType() == QUEEN)
				this->_piece = new Queen(*dynamic_cast<Queen*>(rhs._piece));
			else if (rhs._piece->getType() == ROOK)
				this->_piece = new Rook(*dynamic_cast<Rook*>(rhs._piece));
			else if (rhs._piece->getType() == BISHOP)
				this->_piece = new Bishop(*dynamic_cast<Bishop*>(rhs._piece));
			else if (rhs._piece->getType() == KNIGHT)
				this->_piece = new Knight(*dynamic_cast<Knight*>(rhs._piece));
			else if (rhs._piece->getType() == PAWN)
				this->_piece = new Pawn(*dynamic_cast<Pawn*>(rhs._piece));
		} else
			this->_piece = nullptr;
	}
	return *this;
}

bool Spot::operator==(Spot const& rhs) const
{
	return (this->_x == rhs._x && this->_y == rhs._y);
}

const std::string Spot::getRepr() const
{
	std::stringstream ss;

	ss << this->getColumn() << this->getLine();
	return ss.str();
}

std::ostream& operator<<(std::ostream& o, Spot const& i)
{
	o << i.getRepr();
	return o;
}