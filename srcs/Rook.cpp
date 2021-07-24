/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 18:26:13 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rook.hpp"

Rook::Rook()
	: Piece(ROOK)
{
	return;
}

Rook::Rook(bool isWhite)
	: Piece(ROOK, isWhite)
{
	return;
}

Rook::Rook(Rook const& src)
	: Piece()
{
	*this = src;
	return;
}

Rook::~Rook()
{
	return;
}

Rook& Rook::operator=(Rook const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	return *this;
}

bool Rook::canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	int i;
	int distX = abs(static_cast<int>(end->getX() - start->getX()));
	int distY = abs(static_cast<int>(end->getY() - start->getY()));
	int signX = sgn(end->getX() - start->getX());
	int signY = sgn(end->getY() - start->getY());

	if (!Piece::canMovesWithoutCheck(gameStatus, start, end))
		return false;

	if (distX * distY != 0) {
		return false;
	}

	for (i = 1; start->getX() + i * signX != end->getX(); i++) {
		if (gameStatus->getPiece(start->getX() + i * signX, start->getY()) != NULL) {
			return false;
		}
	}

	for (i = 1; start->getY() + i * signY != end->getY(); i++) {
		if (gameStatus->getPiece(start->getX(), start->getY() + i * signY) != NULL) {
			return false;
		}
	}
	return true;
}

std::vector<Spot*> Rook::validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const
{
	std::vector<Spot*> validSpots;
	size_t			   x;
	size_t			   y;
	Piece*			   pieceKilled;
	Spot*			   destination;

	for (int signX = -1; signX <= 1; signX += 2) {
		for (int i = 1;; i++) {
			x = start->getX() + i * signX;
			y = start->getY();
			if (x > 7)
				break;
			destination = gameStatus->getSpot(x, y);
			pieceKilled = destination->getPiece();
			if (pieceKilled && pieceKilled->isWhite() == this->_isWhite)
				break;
			validSpots.push_back(destination);
			if (pieceKilled)
				break;
		}
	}
	for (int signY = -1; signY <= 1; signY += 2) {
		for (int i = 1;; i++) {
			x = start->getX();
			y = start->getY() + i * signY;
			if (y > 7)
				break;
			destination = gameStatus->getSpot(x, y);
			pieceKilled = destination->getPiece();
			if (pieceKilled && pieceKilled->isWhite() == this->_isWhite)
				break;
			validSpots.push_back(destination);
			if (pieceKilled)
				break;
		}
	}
	return validSpots;
}