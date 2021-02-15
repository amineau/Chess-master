/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:06 by amineau          ###   ########.fr       */
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

bool Queen::canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const
{
	return (Rook::canMoves(gameStatus, start, end) || Bishop::canMoves(gameStatus, start, end));
}

std::vector<Spot*> Queen::validSpots(GameStatus* gameStatus, Spot* start) const
{
	std::vector<Spot*> validSpots;
	std::vector<Spot*> rookValidSpots = Rook::validSpots(gameStatus, start);
	std::vector<Spot*> bishopValidSpots = Bishop::validSpots(gameStatus, start);

	validSpots.reserve(rookValidSpots.size() + bishopValidSpots.size());
	validSpots.insert(validSpots.end(), rookValidSpots.begin(), rookValidSpots.end());
	validSpots.insert(validSpots.end(), bishopValidSpots.begin(), bishopValidSpots.end());
	return validSpots;
}