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

#include "Components/Pieces/Piece.hpp"
#include "Components/Spot.hpp"
#include "Game/GameStatus.hpp"
#include <algorithm>

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

bool Piece::canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	(void)gameStatus;
	(void)start;
	if (end->getPiece() && end->getPiece()->isWhite() == this->isWhite())
		return false;
	return true;
}

bool Piece::canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	return this->canMovesWithoutCheck(gameStatus, start, end) && !gameStatus->moveCausesCheck(start, end);
}

std::vector<Spot*> Piece::validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const
{
	(void)gameStatus;
	(void)start;
	std::vector<Spot*> v;

	return v;
}

std::vector<Spot*> Piece::validSpots(const GameStatus* gameStatus, const Spot* start) const
{
	std::vector<Spot*> validSpots = validSpotsWithoutCheck(gameStatus, start);

	auto new_end = std::remove_if(validSpots.begin(), validSpots.end(), [&](Spot* end) {
		return gameStatus->moveCausesCheck(start, end);
	});
	validSpots.erase(new_end, validSpots.end());
	return validSpots;
}

char Piece::getRepr() const
{
	return pieceRepr[this->getType()];
}

const char* Piece::getUnicodeRepr() const
{
	return pieceUnicodeRepr[this->getType()];
}

Piece* Piece::clone() const
{
	return new Piece(*this);
}

/* Operator Overload */

std::ostream& operator<<(std::ostream& o, Piece const& i)
{
	o << i.getUnicodeRepr();
	return o;
}
