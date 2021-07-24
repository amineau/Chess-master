/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 18:49:53 by amineau          ###   ########.fr       */
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

bool King::canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	int distX = abs(static_cast<int>(end->getX() - start->getX()));
	int distY = abs(static_cast<int>(end->getY() - start->getY()));

	if (!Piece::canMovesWithoutCheck(gameStatus, start, end))
		return false;

	return (distX + distY == 1 || distX * distY == 1);
}

bool King::canKingSideCastlingMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	if (!Piece::canMoves(gameStatus, start, end))
		return false;

	return end->getX() == 6
		&& end->getY() == (_isWhite ? 0 : 7)
		&& gameStatus->getKingSideCastlingAvailable(_isWhite)
		&& gameStatus->getSpot(start->getX() + 1, start->getY())->isEmpty()
		&& end->isEmpty()
		&& !gameStatus->isCheck(_isWhite)
		&& !gameStatus->moveCausesCheck(start, gameStatus->getSpot(start->getX() + 1, start->getY()))
		&& !gameStatus->moveCausesCheck(start, end);
}

bool King::canQueenSideCastlingMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	if (!Piece::canMoves(gameStatus, start, end))
		return false;

	return end->getX() == 2
		&& end->getY() == (_isWhite ? 0 : 7)
		&& gameStatus->getKingSideCastlingAvailable(_isWhite)
		&& gameStatus->getSpot(start->getX() - 1, start->getY())->isEmpty()
		&& end->isEmpty()
		&& !gameStatus->isCheck(_isWhite)
		&& !gameStatus->moveCausesCheck(start, gameStatus->getSpot(start->getX() - 1, start->getY()))
		&& !gameStatus->moveCausesCheck(start, end);
}

std::vector<Spot*> King::validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const
{
	std::vector<Spot*> validSpots;
	Piece*			   pieceKilled;
	Spot*			   destination;

	for (int x = start->getX() - 1; x <= static_cast<int>(start->getX()) + 1; x++) {
		for (int y = start->getY() - 1; y <= static_cast<int>(start->getY()) + 1; y++) {
			if (static_cast<size_t>(x) <= 7 && static_cast<size_t>(y) <= 7) {
				destination = gameStatus->getSpot(x, y);
				pieceKilled = destination->getPiece();
				if (!pieceKilled || pieceKilled->isWhite() != this->_isWhite)
					validSpots.push_back(destination);
			}
		}
	}
	if (this->canKingSideCastlingMoves(gameStatus, start, gameStatus->getSpot(6, (_isWhite ? 0 : 7))))
		validSpots.push_back(gameStatus->getSpot(6, (_isWhite ? 0 : 7)));
	if (this->canQueenSideCastlingMoves(gameStatus, start, gameStatus->getSpot(2, (_isWhite ? 0 : 7))))
		validSpots.push_back(gameStatus->getSpot(2, (_isWhite ? 0 : 7)));
	return validSpots;
}