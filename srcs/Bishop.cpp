/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:09:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bishop.hpp"

Bishop::Bishop()
	: APiece(BISHOP)
{
	return;
}

Bishop::Bishop( size_t index, t_color color )
	: APiece(BISHOP, color, 2 + index * 3, color * BOARD_MAX)
{
	return;
}

Bishop::Bishop( Bishop const & src )
	: APiece()
{
	*this = src;
	return;
}

Bishop::~Bishop() {
	return;
}

Bishop &	Bishop::operator=( Bishop const & rhs ) {
	if (this != &rhs) {
		this->_color = rhs._color;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

Move *	Bishop::calculMoves( std::vector<std::vector<APiece*> > const & pieces, size_t ) {
	Move *	moves = new Move(this);
	int i;

	for (i = 1; this->_y + i <= BOARD_MAX && this->_x + i <= BOARD_MAX
		&& !pieces[this->_y + i][this->_x + i]; i++)
		moves->push(this->_x + i, this->_y + i);
	if (this->_y + i <= BOARD_MAX && this->_x + i <= BOARD_MAX
		&& pieces[this->_y + i][this->_x + i]->getColor() != this->_color)
		moves->push(this->_x + i, this->_y + i, pieces[this->_y + i][this->_x + i]);

	for (i = 1; static_cast<int>(this->_y) - i >= 0 && static_cast<int>(this->_x) - i >=0
		&& !pieces[this->_y - i][this->_x - i]; i++)
		moves->push(this->_x - i, this->_y - i);
	if (static_cast<int>(this->_y) - i >= 0 && static_cast<int>(this->_x) - i >=0
		&& pieces[this->_y - i][this->_x - i]->getColor() != this->_color)
		moves->push(this->_x - i, this->_y - i, pieces[this->_y - i][this->_x - i]);

	for (i = 1; static_cast<int>(this->_y) - i >= 0 && this->_x + i <= BOARD_MAX
		&& !pieces[this->_y - i][this->_x + i]; i++)
		moves->push(this->_x + i, this->_y - i);
	if (static_cast<int>(this->_y) - i >= 0 && this->_x + i <= BOARD_MAX
		&& pieces[this->_y - i][this->_x + i]->getColor() != this->_color)
		moves->push(this->_x + i, this->_y - i, pieces[this->_y - i][this->_x + i]);

	for (i = 1; this->_y + i <= BOARD_MAX && static_cast<int>(this->_x) - i >=0
		&& !pieces[this->_y + i][this->_x - i]; i++)
		moves->push(this->_x - i, this->_y + i);
	if (this->_y + i <= BOARD_MAX && static_cast<int>(this->_x) - i >=0
		&& pieces[this->_y + i][this->_x - i]->getColor() != this->_color)
		moves->push(this->_x - i, this->_y + i, pieces[this->_y + i][this->_x - i]);
	return moves;
}
