/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/28 17:58:21 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Queen.hpp"

Queen::Queen()
	: Piece()
	, _type(QUEEN)
{
	return;
}

Queen::Queen( bool isWhite )
	: Piece(isWhite)
	, _type(QUEEN)
{
	return;
}

Queen::Queen( Queen const & src )
	: Piece()
{
	*this = src;
	return;
}

Queen::~Queen() {
	return;
}

bool	Queen::canMoves(Board board, Spot start, Spot end) const {
	return (Rook::canMoves(board, start, end) || Bishop::canMoves(board, start, end));
}