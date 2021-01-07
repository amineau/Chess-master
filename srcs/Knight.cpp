/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 16:24:11 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knight.hpp"

Knight::Knight()
	: Piece()
{
	return;
}

Knight::Knight(bool isWhite)
	: Piece(KNIGHT, isWhite)
{
	return;
}

Knight::Knight(Knight const& src)
	: Piece()
{
	*this = src;
	return;
}

Knight::~Knight()
{
	return;
}

Knight& Knight::operator=(Knight const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	return *this;
}

bool Knight::canMoves(Board* board, Spot* start, Spot* end) const
{
	int distX = abs(end->getX() - start->getX());
	int distY = abs(end->getY() - start->getY());

	if (!Piece::canMoves(board, start, end))
		return false;
	if (distX * distY != 2)
		return false;
	return true;
}

std::vector<Spot*> Knight::validSpots(Board* board, Spot* start) const
{
	std::vector<Spot*> validSpots;
	size_t			   distX;
	size_t			   distY;
	Piece*			   pieceKilled;
	Spot*			   destination;

	for (int x = start->getX() - 2; x <= static_cast<int>(start->getX()) + 2; x++) {
		for (int y = start->getY() - 2; y <= static_cast<int>(start->getY()) + 2; y++) {
			distX = abs(x - start->getX());
			distY = abs(y - start->getY());
			if (static_cast<size_t>(x) <= 7 && static_cast<size_t>(y) <= 7) {
				destination = board->getBox(x, y);
				pieceKilled = destination->getPiece();
				if (distX * distY == 2 && (!pieceKilled || pieceKilled->isWhite() != this->_isWhite))
					validSpots.push_back(destination);
			}
		}
	}
	return validSpots;
}