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
	: APiece(QUEEN)
{
	return;
}

Queen::Queen( size_t, t_color color )
	: APiece(QUEEN, color, 3, color * BOARD_MAX)
	, Bishop()
	, Rook()
{
	return;
}

Queen::Queen( Queen const & src )
	: APiece()
	, Bishop()
	, Rook()
{
	*this = src;
	return;
}

Queen::~Queen() {
	return;
}

Queen &	Queen::operator=( Queen const & rhs ) {
	if (this != &rhs) {
		this->_color = rhs._color;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

Move *	Queen::calculMoves( std::vector<std::vector<APiece*> > const & pieces, size_t round) {
	Move *	moves = new Move(this);

	*moves = *Bishop::calculMoves(pieces, round) + *Rook::calculMoves(pieces, round);
	return moves;
}
