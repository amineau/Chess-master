/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:22:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "King.hpp"

King::King()
	: APiece(KING)
{
	return;
}

King::King( size_t, t_color color )
	: APiece(KING, color, 4, color * BOARD_MAX)
{
	return;
}

King::King( King const & src )
	: APiece()
{
	*this = src;
	return;
}

King::~King() {
	return;
}

King &	King::operator=( King const & rhs ) {
	if (this != &rhs) {
		this->_color = rhs._color;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

Move *	King::calculMoves( std::vector<std::vector<APiece*> > const & pieces, size_t ) {
	int x;
	int y;
	Move *	moves = new Move(this);

	for (int i = -1; i <= 1; i++) {
		x = this->_x + i;
		if (x >= 0 && x <= BOARD_MAX) {
			for (int j = -1; j <= 1; j++) {
				y = this->_y + j;
				if (y >= 0 && y <= BOARD_MAX && (i || j)) {
					if (pieces[y][x] && pieces[y][x]->getColor() != this->_color)
						moves->push(x, y, pieces[y][x]);
					else if (!pieces[y][x])
						moves->push(x, y);
				}
			}
		}
	}
	// Rook
	if (!this->_last_move) {
		for (int i = 1; this->_x - i == 0 || (this->_x - i > 0 && !pieces[this->_y][this->_x - i]); i++) {
			// check echec
			if (this->_x - i == 0 && pieces[this->_y][this->_x - i]->getLastMove() == 0)
				moves->push(this->_x - 2, this->_y);
		}
		for (int i = 1; this->_x + i == BOARD_MAX || (this->_x + i < BOARD_MAX && !pieces[this->_y][this->_x + i]); i++) {
			// check echec
			if (this->_x + i == BOARD_MAX && pieces[this->_y][this->_x + i]->getLastMove() == 0)
				moves->push(this->_x + 2, this->_y);
		}
	}
	return moves;
}
