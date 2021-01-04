/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2021/01/04 15:54:59 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knight.hpp"

Knight::Knight()
	: Piece()
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

bool Knight::canMoves(Board* board, Spot* start, Spot* end) const
{
	int distX = abs(end->getX() - start->getX());
	int distY = abs(end->getY() - start->getY());

	if (!Piece::canMoves(board, start, end))
		return false;
	if (distX * distY != 2)
		return false;
	return true;
}