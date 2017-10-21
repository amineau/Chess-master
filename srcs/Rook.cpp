/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 03:17:29 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rook.hpp"

Rook::Rook( size_t index, t_color color )
	: APiece(ROOK, color, index * 7, color * 7)
{
	return;
}

Rook::Rook( Rook const & src )
{
	*this = src;
	return;
}

Rook::~Rook() {
	return;
}

Rook &	Rook::operator=( Rook const & rhs ) {
	if (this != &rhs) {
		this->_color = rhs._color;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

std::vector<Move> &	Rook::getMoving( std::vector<APiece>& pieces, size_t ) {
	std::vector<Move> * moves = new std::vector<Move>();
	std::vector<APiece>::iterator it;
	size_t				x_min = 0;
	size_t				x_max = 7;
	size_t				y_min = 0;
	size_t				y_max = 7;

	for (it = pieces.begin(); it != pieces.end() && (x_min != x_max || y_min != y_max); it++) {
		if (it->getX() == this->_x) {
			if (it->getY() > this->_y && it->getY() < y_max) {
				if (it->getColor() != this->_color)
					moves->push_back(Move(this->_x, it->getY(), &(*it)));
				y_max = it->getY() - 1;
			} else if (it->getY() < this->_y && it->getY() > y_min) {
				if (it->getColor() != this->_color)
					moves->push_back(Move(this->_x, it->getY(), &(*it)));
				y_min = it->getY() + 1;
			}
		} else if (it->getY() == this->_y) {
			if (it->getX() > this->_x && it->getX() < x_max) {
				if (it->getColor() != this->_color)
					moves->push_back(Move(it->getX(), this->_y, &(*it)));
				x_max = it->getX() - 1;
			} else if (it->getX() < this->_x && it->getX() > x_min) {
				if (it->getColor() != this->_color)
					moves->push_back(Move(it->getX(), this->_y, &(*it)));
				x_min = it->getX() + 1;
			}
		}
	}
	while (x_min != this->_x)
		moves->push_back(Move(x_min++, this->_y, NULL));
	while (x_max != this->_x)
		moves->push_back(Move(x_max--, this->_y, NULL));
	while (y_min != this->_y)
		moves->push_back(Move(this->_x, y_min++, NULL));
	while (y_max != this->_y)
		moves->push_back(Move(this->_x, y_max--, NULL));
	return *moves;
}
