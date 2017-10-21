/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/22 00:56:30 by amineau          ###   ########.fr       */
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

	for (it = pieces.begin(); it != pieces.end() && (x_min != x_max || y_min != y_max); it++) {
		APiece *	instance = &(**it);
		
		if (instance->getX() == this->_x) {
			if (instance->getY() > this->_y && instance->getY() <= y_max) {
				if (instance->getColor() != this->_color)
					moves->push_back(Move(this->_x, instance->getY(), instance));
				y_max = instance->getY() - 1;
			} else if (instance->getY() < this->_y && instance->getY() >= y_min) {
				if (instance->getColor() != this->_color)
					moves->push_back(Move(this->_x, instance->getY(), instance));
				y_min = instance->getY() + 1;
			}
		} else if (instance->getY() == this->_y) {
			if (instance->getX() > this->_x && instance->getX() <= x_max) {
				if (instance->getColor() != this->_color)
					moves->push_back(Move(instance->getX(), this->_y, instance));
				x_max = instance->getX() - 1;
			} else if (instance->getX() < this->_x && instance->getX() >= x_min) {
				if (instance->getColor() != this->_color)
					moves->push_back(Move(instance->getX(), this->_y, instance));
				x_min = instance->getX() + 1;
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
