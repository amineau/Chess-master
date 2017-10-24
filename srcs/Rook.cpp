/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/24 02:09:38 by amineau          ###   ########.fr       */
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

std::vector<Move> &	Rook::getMoving( std::vector<std::vector<APiece*> > const & pieces, size_t ) {
	std::vector<Move> * moves = new std::vector<Move>();
	int x;
	int y;

	for (x = this->_x + 1; x <= BOARD_MAX && !pieces[this->_y][x];x++)
		moves->push_back(Move(x, this->_y, NULL));
	if (x <= BOARD_MAX && pieces[this->_y][x]->getColor() != this->_color)
		moves->push_back(Move(x, this->_y, pieces[this->_y][x]));

	for (x = this->_x - 1; x >= 0 && !pieces[this->_y][x];x--)
		moves->push_back(Move(x, this->_y, NULL));
	if (x >= 0 && pieces[this->_y][x]->getColor() != this->_color)
		moves->push_back(Move(x, this->_y, pieces[this->_y][x]));

	for (y = this->_y + 1; y <= BOARD_MAX && !pieces[y][this->_x];y++)
		moves->push_back(Move(this->_x, y, NULL));
	if (y <= BOARD_MAX && pieces[y][this->_x]->getColor() != this->_color)
		moves->push_back(Move(this->_x, y, pieces[y][this->_x]));

	for (y = this->_y - 1; y >= 0 && !pieces[y][this->_x];y--)
		moves->push_back(Move(this->_x, y, NULL));
	if (y >= 0 && pieces[y][this->_x]->getColor() != this->_color)
		moves->push_back(Move(this->_x, y, pieces[y][this->_x]));

	return *moves;
}
