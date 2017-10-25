/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/25 21:34:31 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knight.hpp"

Knight::Knight()
	: APiece(KNIGHT)
{
	return;
}

Knight::Knight( size_t index, t_color color )
	: APiece(KNIGHT, color, 1 + index * 5, color * BOARD_MAX)
{
	return;
}

Knight::Knight( Knight const & src )
	: APiece()
{
	*this = src;
	return;
}

Knight::~Knight() {
	return;
}

Knight &	Knight::operator=( Knight const & rhs ) {
	if (this != &rhs) {
		this->_color = rhs._color;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

std::vector<Move> &	Knight::getMoving( std::vector<std::vector<APiece*> > const & pieces, size_t ) {
	std::vector<Move> * moves = new std::vector<Move>();
	int tab[4] = { -2, -1, 2, 1 };
	int x;
	int y;

	for (int i = 0; i < 4; i++) {
		x = this->_x + tab[i];
		if (x >= 0 && x <= BOARD_MAX) {
			for (int j = 0; j < 4; j++) {
				y = this->_y + tab[j];
				if (y >= 0 && y <= BOARD_MAX && i%2 != j%2) {
					if (pieces[y][x] && pieces[y][x]->getColor() != this->_color)
						moves->push_back(Move(x, y, pieces[y][x]));
					else if (!pieces[y][x])
						moves->push_back(Move(x, y, NULL));
				}
			}
		}
	}

	return *moves;
}
