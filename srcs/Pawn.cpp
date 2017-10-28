/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2017/10/28 17:57:52 by amineau          ###   ########.fr       */
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
		this->_last_y = rhs._last_y;
	}
	return *this;
}

/* Members functions */

void	Pawn::setPosition(size_t x, size_t y, size_t round) {
	this->_last_y = this->_y;
	APiece::setPosition(x, y, round);
}

/* Accessors */

size_t	Pawn::getLastY() const {
	return this->_last_y;
}


Move *	Pawn::calculMoves( std::vector<std::vector<APiece*> > const & pieces, size_t round ) {
	Move *	moves = new Move(this);
	Pawn *	pawn;
	int		x;
	int		direction = this->_color == WHITE ? 1 : -1;
	size_t	y_move = static_cast<int>(this->_y) + 1 * direction;
	
	(void)round;
	if (this->_x + 1 <= BOARD_MAX
		&& pieces[y_move][this->_x + 1]
		&& pieces[y_move][this->_x + 1]->getColor() != this->_color)
		moves->push(this->_x + 1, y_move, pieces[y_move][this->_x + 1]);
	if (static_cast<int>(this->_x) - 1 >= 0
		&& pieces[y_move][this->_x - 1]
		&& pieces[y_move][this->_x - 1]->getColor() != this->_color)
		moves->push(this->_x - 1, y_move, pieces[y_move][this->_x - 1]);

	// Moving list
	if (!pieces[y_move][this->_x]) {
		moves->push(this->_x, y_move);
		if (this->_y == static_cast<size_t>(this->_color) * 5 + 1
			&& !pieces[static_cast<int>(this->_y) + 2 * direction][this->_x])
			moves->push(this->_x, static_cast<int>(this->_y) + 2 * direction);
	}

	// En Passant Capture
	if (static_cast<int>(this->_y) == 4 - this->_color)
		for (int i = -1; i <= 1; i += 2) {
			x = static_cast<int>(this->_x) + i;
			pawn = dynamic_cast<Pawn*>(pieces[this->_y][x]);
			if (x >= 0 && x <= BOARD_MAX && pawn
				&& pawn->getColor() != this->_color
				&& static_cast<int>(pawn->getLastY()) == pawn->getColor() * 5 + 1
				&& pawn->getLastMove() == round - 1)
				moves->push(x, 2 + pawn->getColor() * 3, pawn);
		}
	return moves;
}
