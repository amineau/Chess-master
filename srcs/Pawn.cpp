/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 19:24:14 by amineau          ###   ########.fr       */
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

bool Pawn::canMoves(Board* board, Spot* start, Spot* end) const
{
	bool isWhite = start->getPiece()->isWhite();
	int	 direction = isWhite ? 1 : -1;
	int	 deltaX = end->getX() - start->getX();
	int	 deltaY = end->getY() - start->getY();

	if (!Piece::canMoves(board, start, end))
		return false;
	if (end->getPiece() == NULL) {
		if (start->getX() != end->getX())
			return false;
		else if ((start->getY() == 1 && isWhite) || (start->getY() == 6 && !isWhite)) {
			if (deltaY != direction || deltaY != direction * 2)
				return false;
			if (deltaY == direction * 2 && board->getBox(start->getX(), start->getY() + direction)->getPiece() != NULL)
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

std::vector<Spot*> Pawn::validSpots(Board* board, Spot* start) const
{
	std::vector<Spot*> validSpots;
	int				   direction = this->_isWhite ? 1 : -1;
	size_t			   initialY = this->_isWhite ? 1 : 6;
	Piece*			   pieceKilled;
	Spot*			   destination;

	if (start->getY() + direction <= 7) {
		destination = board->getBox(start->getX(), start->getY() + direction);
		if (!destination->getPiece()) {
			validSpots.push_back(destination);
			if (start->getY() == initialY && !board->getBox(start->getX(), start->getY() + 2 * direction)->getPiece())
				validSpots.push_back(board->getBox(start->getX(), start->getY() + 2 * direction));
		}
		for (int i = -1; i <= 1; i += 2) {
			if (start->getX() + i <= 7) {
				destination = board->getBox(start->getX() + i, start->getY() + direction);
				pieceKilled = destination->getPiece();
				if (pieceKilled && pieceKilled->isWhite() != this->_isWhite)
					validSpots.push_back(destination);
			}
		}
	}
	return validSpots;
}