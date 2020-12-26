/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:10:33 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knight.hpp"

Knight::Knight()
	: Piece()
	, _type(KNIGHT)
{
	return;
}

Knight::Knight(bool isWhite)
	: Piece(isWhite)
	, _type(KNIGHT)
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

bool Knight::canMoves(Board board, Spot start, Spot end) const
{
	int distX = abs(end.getX() - start.getX());
	int distY = abs(end.getY() - start.getY());

	if (!Piece::canMoves(board, start, end))
		return false;
	if (distX * distY != 2)
		return false;
	return true;
}