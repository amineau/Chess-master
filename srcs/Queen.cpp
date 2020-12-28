/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2020/12/29 00:21:33 by amineau          ###   ########.fr       */
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

bool Queen::canMoves(Board board, Spot start, Spot end) const
{
	return (Rook::canMoves(board, start, end) || Bishop::canMoves(board, start, end));
}