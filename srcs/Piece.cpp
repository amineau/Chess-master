/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:49:45 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:21:29 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Piece.hpp"

Piece::Piece()
{
	// std::cout << "Constructor Piece called" << std::endl;
	return;
}

Piece::Piece(t_type typePiece)
	: _type(typePiece)
	, _isKilled(false)
{
	// std::cout << "Constructor Piece called for child " << pieceRepr[this->_type] << std::endl;
	return;
}

Piece::Piece(t_type typePiece, bool isWhite)
	: _isWhite(isWhite)
	, _type(typePiece)
	, _isKilled(false)
{
	// std::cout << "Constructor Piece called for child " << pieceRepr[this->_type] << std::endl;
	return;
}

Piece::Piece(Piece const& src)
{
	*this = src;
	// std::cout << "Constructor Piece by REF called for child " << pieceRepr[this->_type] << std::endl;
	return;
}

Piece::~Piece()
{
	// std::cout << "Deconstructor Piece called for child " << pieceRepr[this->_type] << std::endl;
	return;
}

Piece& Piece::operator=(Piece const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	// std::cout << "Constructor Piece by operator= called for child " << pieceRepr[this->_type] << std::endl;
	return *this;
}

/* Accessors */

bool Piece::isWhite() const
{
	return this->_isWhite;
}

void Piece::setIsWhite(bool isWhite)
{
	this->_isWhite = isWhite;
}

t_type Piece::getType() const
{
	return this->_type;
}

/* Members functions */

bool Piece::isKilled() const
{
	return this->_isKilled;
}

void Piece::killed()
{
	this->_isKilled = true;
}

bool Piece::canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const
{
	(void)gameStatus;
	if (start == end)
		return false;
	if (end->getPiece() && end->getPiece()->isWhite() == this->isWhite())
		return false;
	return true;
}

std::vector<Spot*> Piece::validSpots(const GameStatus* gameStatus, const Spot* start) const
{
	(void)gameStatus;
	(void)start;
	std::vector<Spot*> v;

	return v;
}

Piece* Piece::clone() const
{
	return new Piece(*this);
}

/* Operator Overload */

std::ostream& operator<<(std::ostream& o, Piece const& i)
{
	const char repr = i.isWhite() ? toupper(pieceRepr[i.getType()]) : pieceRepr[i.getType()];
	o << repr;
	return o;
}