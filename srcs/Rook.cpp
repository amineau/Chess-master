/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/22 23:42:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rook.hpp"

Rook::Rook()
	: APiece(ROOK)
{
	return;
}

Rook::Rook( size_t index, t_color color )
	: APiece(ROOK, color, index * BOARD_MAX, color * BOARD_MAX)
{
	return;
}

Rook::Rook( Rook const & src )
	: APiece()
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

std::vector<Move> &	Rook::getMoving( std::vector<APiece*>& pieces, size_t ) {
	std::vector<Move> * moves = new std::vector<Move>();
	std::vector<APiece*>::iterator it;
	size_t				x_min = 0;
	size_t				x_max = BOARD_MAX;
	size_t				y_min = 0;
	size_t				y_max = BOARD_MAX;
	APiece *			taking[4] = {};

	for (it = pieces.begin(); it != pieces.end() && (x_min != x_max || y_min != y_max); it++) {
		APiece *	instance = &(**it);

		if (instance->getX() == this->_x) {
			if (instance->getY() > this->_y && instance->getY() <= y_max) {
				taking[0] = (instance->getColor() != this->_color) ? instance : NULL;
				y_max = instance->getY() - 1;
			} else if (instance->getY() < this->_y && instance->getY() >= y_min) {
				taking[1] = (instance->getColor() != this->_color) ? instance : NULL;
				y_min = instance->getY() + 1;
			}
		} else if (instance->getY() == this->_y) {
			if (instance->getX() > this->_x && instance->getX() <= x_max) {
				taking[2] = (instance->getColor() != this->_color) ? instance : NULL;
				x_max = instance->getX() - 1;
			} else if (instance->getX() < this->_x && instance->getX() >= x_min) {
				taking[3] = (instance->getColor() != this->_color) ? instance : NULL;
				x_min = instance->getX() + 1;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		if (taking[i])
			moves->push_back(Move(taking[i]->getX(), taking[i]->getY(), taking[i]));
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
