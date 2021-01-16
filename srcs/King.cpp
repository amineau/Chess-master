/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/08 19:13:31 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "King.hpp"

King::King()
	: Piece(KING)
	, _castlingDone(false)
{
	return;
}

King::King(bool isWhite)
	: Piece(KING, isWhite)
	, _castlingDone(false)
{
	return;
}

King::King(King const& src)
	: Piece()
{
	*this = src;
	return;
}

King::~King()
{
	return;
}

King& King::operator=(King const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_type = rhs._type;
		this->_isWhite = rhs._isWhite;
		this->_castlingDone = rhs._castlingDone;
	}
	return *this;
}

bool King::isCastlingDone() const
{
	return this->_castlingDone;
}

void King::setCastlingDone(bool castlingDone)
{
	this->_castlingDone = castlingDone;
}

bool King::canMoves(Board* board, Spot* start, Spot* end) const
{
	int distX = abs(end->getX() - start->getX());
	int distY = abs(end->getY() - start->getY());

	if (!Piece::canMoves(board, start, end))
		return false;

	return distX + distY == 1 || distX * distY == 1;
}

std::vector<Spot*> King::validSpots(Board* board, Spot* start) const
{
	std::vector<Spot*> validSpots;
	Piece*			   pieceKilled;
	Spot*			   destination;

	for (int x = start->getX() - 1; x <= static_cast<int>(start->getX()) + 1; x++) {
		for (int y = start->getY() - 1; y <= static_cast<int>(start->getY()) + 1; y++) {
			if (static_cast<size_t>(x) <= 7 && static_cast<size_t>(y) <= 7) {
				destination = board->getBox(x, y);
				pieceKilled = destination->getPiece();
				if (!pieceKilled || pieceKilled->isWhite() != this->_isWhite)
					validSpots.push_back(destination);
			}
		}
	}
	return validSpots;
}