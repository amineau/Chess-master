/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 21:41:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knight.hpp"

Knight::Knight()
	: Piece(KNIGHT)
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

bool Knight::canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const
{
	int distX = abs(static_cast<int>(end->getX() - start->getX()));
	int distY = abs(static_cast<int>(end->getY() - start->getY()));

	if (!Piece::canMoves(gameStatus, start, end))
		return false;
	if (distX * distY != 2)
		return false;
	return true;
}

std::vector<Spot*> Knight::validSpots(const GameStatus* gameStatus, const Spot* start) const
{
	std::vector<Spot*> validSpots;
	size_t			   distX;
	size_t			   distY;
	Piece*			   pieceKilled;
	Spot*			   destination;

	if (gameStatus->getCurrentTurn()->isWhite() == this->_isWhite)
		for (int x = start->getX() - 2; x <= static_cast<int>(start->getX()) + 2; x++) {
			for (int y = start->getY() - 2; y <= static_cast<int>(start->getY()) + 2; y++) {
				distX = abs(static_cast<int>(x - start->getX()));
				distY = abs(static_cast<int>(y - start->getY()));
				if (static_cast<size_t>(x) <= 7 && static_cast<size_t>(y) <= 7) {
					destination = gameStatus->getBox(x, y);
					pieceKilled = destination->getPiece();
					if (distX * distY == 2 && (!pieceKilled || pieceKilled->isWhite() != this->_isWhite))
						validSpots.push_back(destination);
				}
			}
		}
	return validSpots;
}