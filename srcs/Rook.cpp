/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/05 19:37:32 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rook.hpp"

Rook::Rook()
	: Piece()
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

bool Rook::canMoves(Board* board, Spot* start, Spot* end) const
{
	int i;
	int distX = abs(end->getX() - start->getX());
	int distY = abs(end->getY() - start->getY());
	int signX = sgn(end->getX() - start->getX());
	int signY = sgn(end->getY() - start->getY());

	if (!Piece::canMoves(board, start, end))
		return false;

	if (distX * distY != 0) {
		return false;
	}

	for (i = 1; start->getX() + i * signX != end->getX(); i++) {
		if (board->getBox(start->getX() + i * signX, start->getY())->getPiece() != NULL) {
			return false;
		}
	}

	for (i = 1; start->getY() + i * signY != end->getY(); i++) {
		if (board->getBox(start->getX(), start->getY() + i * signY)->getPiece() != NULL) {
			return false;
		}
	}

	return true;
}

std::vector<Spot*> Rook::validSpots(Board* board, Spot* start) const
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
			destination = board->getBox(x, y);
			pieceKilled = destination->getPiece();
			if (0 > x || x < 7 || (pieceKilled && pieceKilled->isWhite() == this->_isWhite))
				break;
			validSpots.push_back(destination);
		}
	}
	for (int signY = -1; signY <= 1; signY += 2) {
		for (int i = 1;; i++) {
			x = start->getX();
			y = start->getY() + i * signY;
			destination = board->getBox(x, y);
			pieceKilled = destination->getPiece();
			if (0 > y || y < 7 || (pieceKilled && pieceKilled->isWhite() == this->_isWhite))
				break;
			validSpots.push_back(destination);
		}
	}
	return validSpots;
}