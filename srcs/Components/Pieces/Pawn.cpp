/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:27:51 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Components/Pieces/Pawn.hpp"

Pawn::Pawn()
	: Piece(PAWN)
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

bool Pawn::canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	bool isWhite = this->isWhite();
	int	 direction = isWhite ? 1 : -1;
	int	 deltaX = end->getX() - start->getX();
	int	 deltaY = end->getY() - start->getY();

	if (!Piece::canMovesWithoutCheck(gameStatus, start, end))
		return false;
	if (end->getPiece() == NULL) {
		if (start->getX() != end->getX())
			return false;
		else if ((start->getY() == 1 && isWhite) || (start->getY() == 6 && !isWhite)) {
			if (deltaY != direction && deltaY != direction * 2)
				return false;
			if (deltaY == direction * 2 && gameStatus->getPiece(start->getX(), start->getY() + direction) != NULL)
				return false;
		} else if (deltaY != direction)
			return false;
	} else if (abs(deltaX) != 1 || deltaY != direction)
		return false;
	return true;
}
bool Pawn::canMovesEnPassant(GameStatus* gameStatus, Spot* start, Spot* end, Spot* spotPieceKilled) const
{
	bool								 isWhite = this->isWhite();
	int									 direction = isWhite ? 1 : -1;
	int									 deltaX = end->getX() - start->getX();
	int									 deltaY = end->getY() - start->getY();
	std::vector<std::pair<Spot*, Spot*>> moves = {
		std::make_pair(start, spotPieceKilled),
		std::make_pair(spotPieceKilled, end)
	};

	if (!Piece::canMovesWithoutCheck(gameStatus, start, end))
		return false;
	return abs(deltaX) == 1 && deltaY == direction
		&& !gameStatus->moveCausesCheck(moves);
}

std::vector<Spot*> Pawn::validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const
{
	std::vector<Spot*> validSpots;
	const int		   direction = this->_isWhite ? 1 : -1;
	const size_t	   initialY = this->_isWhite ? 1 : 6;
	Piece*			   pieceKilled;
	Spot*			   destination;
	const Board*	   board = gameStatus->getBoard();

	if (start->getY() + direction <= 7) {
		destination = board->getSpot(start->getX(), start->getY() + direction);
		if (!destination->getPiece()) {
			validSpots.push_back(destination);
			if (start->getY() == initialY && !board->getSpot(start->getX(), start->getY() + 2 * direction)->getPiece())
				validSpots.push_back(board->getSpot(start->getX(), start->getY() + 2 * direction));
		}
		for (int i = -1; i <= 1; i += 2) {
			if (start->getX() + i <= 7) {
				destination = board->getSpot(start->getX() + i, start->getY() + direction);
				pieceKilled = destination->getPiece();
				if ((pieceKilled && pieceKilled->isWhite() != this->_isWhite)
					|| gameStatus->getEnPassantTargetSpot() == destination)
					// TODO: La prise en passant qui met le roi en echec en enlevant la pièce adverse
					// n'enlève pas cette destination. Exemple : "4k3/8/8/r2Pp2K/8/8/8/8 w - e6 0 1"
					validSpots.push_back(destination);
			}
		}
	}
	return validSpots;
}