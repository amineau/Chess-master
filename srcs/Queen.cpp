/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 18:23:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Queen.hpp"

Queen::Queen()
	: Piece(QUEEN)
{
	return;
}

Queen::Queen(bool isWhite)
	: Piece(QUEEN, isWhite)
{
	return;
}

Queen::Queen(Queen const& src)
	: Piece()
	, Bishop()
	, Rook()
{
	*this = src;
	return;
}

Queen::~Queen()
{
	return;
}

Queen& Queen::operator=(Queen const& rhs)
{
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	return *this;
}

bool Queen::canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const
{
	return (Rook::canMovesWithoutCheck(gameStatus, start, end) || Bishop::canMovesWithoutCheck(gameStatus, start, end));
}

std::vector<Spot*> Queen::validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const
{
	std::vector<Spot*> validSpots;
	std::vector<Spot*> rookValidSpots = Rook::validSpotsWithoutCheck(gameStatus, start);
	std::vector<Spot*> bishopValidSpots = Bishop::validSpotsWithoutCheck(gameStatus, start);

	validSpots.reserve(rookValidSpots.size() + bishopValidSpots.size());
	validSpots.insert(validSpots.end(), rookValidSpots.begin(), rookValidSpots.end());
	validSpots.insert(validSpots.end(), bishopValidSpots.begin(), bishopValidSpots.end());
	return validSpots;
}