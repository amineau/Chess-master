/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 14:39:01 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Queen.hpp"

Queen::Queen()
	: Piece()
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

bool Queen::canMoves(Board* board, Spot* start, Spot* end) const
{
	return (Rook::canMoves(board, start, end) || Bishop::canMoves(board, start, end));
}

std::vector<Spot*> Queen::validSpots(Board* board, Spot* start) const
{
	std::vector<Spot*> validSpots;
	std::vector<Spot*> rookValidSpots = Rook::validSpots(board, start);
	std::vector<Spot*> bishopValidSpots = Bishop::validSpots(board, start);

	validSpots.reserve(rookValidSpots.size() + bishopValidSpots.size());
	validSpots.insert(validSpots.end(), rookValidSpots.begin(), rookValidSpots.end());
	validSpots.insert(validSpots.end(), bishopValidSpots.begin(), bishopValidSpots.end());
	return validSpots;
}