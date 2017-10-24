/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2017/10/24 23:12:51 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"

Pawn::Pawn()
	: APiece(PAWN)
{
	return;
}

Pawn::Pawn( size_t index, t_color color )
	: APiece(PAWN, color, index, color * 5 + 1)
{
	return;
}

Pawn::Pawn( Pawn const & src )
	: APiece()
{
	*this = src;
	return;
}

Pawn::~Pawn() {
	return;
}

Pawn &	Pawn::operator=( Pawn const & rhs ) {
	if (this != &rhs) {
		this->_color = rhs._color;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

std::vector<Move> &	Pawn::getMoving( std::vector<std::vector<APiece*> > const & pieces, size_t round ) {
	std::vector<Move> * moves = new std::vector<Move>();
	int					direction = this->_color == WHITE ? 1 : -1;
	size_t				y_move = static_cast<int>(this->_y) + 1 * direction;
	
	(void)round;
	if (this->_x + 1 <= BOARD_MAX
		&& pieces[y_move][this->_x + 1]
		&& pieces[y_move][this->_x + 1]->getColor() != this->_color)
		moves->push_back(Move(this->_x + 1, y_move, pieces[y_move][this->_x + 1]));
	if (static_cast<int>(this->_x) - 1 >= 0
		&& pieces[y_move][this->_x - 1]
		&& pieces[y_move][this->_x - 1]->getColor() != this->_color)
		moves->push_back(Move(this->_x - 1, y_move, pieces[y_move][this->_x - 1]));

	// Moving list
	if (!pieces[y_move][this->_x]) {
		moves->push_back(Move(this->_x, y_move, NULL));
		if (this->_y == static_cast<size_t>(this->_color) * 5 + 1
			&& !pieces[static_cast<int>(this->_y) + 2 * direction][this->_x])
			moves->push_back(Move(this->_x, static_cast<int>(this->_y) + 2 * direction, NULL));
	}
	return *moves;
}
