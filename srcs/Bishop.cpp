/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2020/12/29 00:17:34 by amineau          ###   ########.fr       */
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

bool Bishop::canMoves(Board board, Spot start, Spot end) const
{
	int i;
	int signX = sgn(end.getX() - start.getX());
	int signY = sgn(end.getY() - start.getY());
	int distX = abs(end.getX() - start.getX());
	int distY = abs(end.getY() - start.getY());

	if (!Piece::canMoves(board, start, end))
		return false;

	if (distX != distY) {
		return false;
	}

	for (i = 1; start.getX() + i * signX != end.getX(); i++) {
		if (board.getBox(start.getX() + i * signX, start.getY() + i * signY).getPiece() != NULL) {
			return false;
		}
	}

	return true;
}
