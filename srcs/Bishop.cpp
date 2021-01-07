/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 19:22:24 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bishop.hpp"

Bishop::Bishop()
	: Piece()
{
	return;
}

Bishop::Bishop(bool isWhite)
	: Piece(BISHOP, isWhite)
{
	return;
}

Bishop::Bishop(Bishop const& src)
	: Piece()
{
	*this = src;
	return;
}

Bishop::~Bishop()
{
	return;
}

Bishop& Bishop::operator=(Bishop const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	return *this;
}

bool Bishop::canMoves(Board* board, Spot* start, Spot* end) const
{
	int i;
	int signX = sgn(end->getX() - start->getX());
	int signY = sgn(end->getY() - start->getY());
	int distX = abs(end->getX() - start->getX());
	int distY = abs(end->getY() - start->getY());

	if (!Piece::canMoves(board, start, end))
		return false;

	if (distX != distY) {
		return false;
	}

	for (i = 1; start->getX() + i * signX != end->getX(); i++) {
		if (board->getBox(start->getX() + i * signX, start->getY() + i * signY)->getPiece() != NULL) {
			return false;
		}
	}

	return true;
}

std::vector<Spot*> Bishop::validSpots(Board* board, Spot* start) const
{
	std::vector<Spot*> validSpots;
	size_t			   x;
	size_t			   y;
	Piece*			   pieceKilled;
	Spot*			   destination;

	for (int signX = -1; signX <= 1; signX += 2) {
		for (int signY = -1; signY <= 1; signY += 2) {
			for (int i = 1;; i++) {
				x = start->getX() + i * signX;
				y = start->getY() + i * signY;
				if (x > 7 || y > 7)
					break;
				destination = board->getBox(x, y);
				pieceKilled = destination->getPiece();
				if (pieceKilled && pieceKilled->isWhite() == this->_isWhite)
					break;
				validSpots.push_back(destination);
			}
		}
	}
	return validSpots;
}