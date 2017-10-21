/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 16:45:48 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"

Pawn::Pawn( size_t index, t_color color )
	: APiece(PAWN, color, index, color * 5 + 1)
{
	return;
}

Pawn::Pawn( Pawn const & src )
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

std::vector<Move> &	Pawn::getMoving( std::vector<APiece*>& pieces, size_t round ) {
	std::vector<Move> * moves = new std::vector<Move>();
	int					direction = this->_color == WHITE ? 1 : -1;

	for (std::vector<APiece*>::iterator it = pieces.begin(); it != pieces.end(); it++) {
		if (round)
			;
	}
	std::cout << static_cast<int>(this->_y) + 1 * direction << std::endl;
	moves->push_back(Move(this->_x, static_cast<int>(this->_y) + 1 * direction, NULL));
	if (this->_y == this->_color * 5 + 1)
		moves->push_back(Move(this->_x, static_cast<int>(this->_y) + 2 * direction, NULL));
	return *moves;
}
