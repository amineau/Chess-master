/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2020/12/29 00:21:06 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"

Pawn::Pawn()
{
	return;
}

Pawn::Pawn(bool isWhite)
	: Piece(PAWN, isWhite)
{
	return;
}

Pawn::Pawn(Pawn const& src)
	: Piece()
{
	*this = src;
	return;
}

Pawn::~Pawn() { return; }

Pawn& Pawn::operator=(Pawn const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	return *this;
}

/* Members functions */

bool Pawn::canMoves(Board board, Spot start, Spot end) const
{
	bool isWhite = start.getPiece()->isWhite();
	int	 direction = isWhite ? 1 : -1;
	int	 deltaX = end.getX() - start.getX();
	int	 deltaY = end.getY() - start.getY();

	if (!Piece::canMoves(board, start, end))
		return false;
	if (end.getPiece() == NULL) {
		if (start.getX() != end.getX())
			return false;
		else if ((start.getY() == 1 && isWhite) || (start.getY() == 6 && !isWhite)) {
			if (deltaY != direction || deltaY != direction * 2)
				return false;
			if (deltaY == direction * 2 && board.getBox(start.getX(), start.getY() + direction).getPiece() != NULL)
				return false;
		} else {
			if (deltaY != direction)
				return false;
		}
	} else {
		if (abs(deltaX) != 1 || deltaY != direction)
			return false;
	}
	return true;
}
