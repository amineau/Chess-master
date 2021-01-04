/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/04 15:57:19 by amineau          ###   ########.fr       */
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
		if (board->getBox(start->getX(), start->getY() + i * signX)->getPiece() != NULL) {
			return false;
		}
	}

	return true;
}