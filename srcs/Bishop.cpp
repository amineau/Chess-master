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
	: Piece()
	, _type(BISHOP)
{
	return;
}

Bishop::Bishop( bool isWhite )
	: Piece(isWhite)
	, _type(BISHOP)
{
	return;
}

Bishop::Bishop( Bishop const & src )
	: Piece()
{
	*this = src;
	return;
}

Bishop::~Bishop()
{
	return;
}


int sgn(int valeur) {
    if (valeur < 0) return -1;
    if (valeur == 0) return 0;
    return 1;
} 

bool		Bishop::canMoves(Board board, Spot start, Spot end) const {
	int i;
	int signX = sgn(end.getX() - start.getX());
	int signY = sgn(end.getY() - start.getY());
	int distX = abs(end.getX() - start.getX());
	int distY = abs(end.getY() - start.getY());

	if (!Piece::canMoves(board, start, end)) return false;
	
	if (distX != distY) {
		return false;
	}

	for (i = 1; start.getX() + i * signX != end.getX(); i++) {
		if (board.getBox(start.getX() + i * signX, start.getY() + i * signY)->getPiece() != NULL) {
			return false;
		}
	}

	return true;
}

// Move *	Bishop::calculMoves( std::vector<std::vector<Piece*> > const & pieces, size_t ) {
// 	Move *	moves = new Move(this);
// 	int i;

// 	for (i = 1; this->_y + i <= BOARD_MAX && this->_x + i <= BOARD_MAX
// 		&& !pieces[this->_y + i][this->_x + i]; i++)
// 		moves->push(this->_x + i, this->_y + i);
// 	if (this->_y + i <= BOARD_MAX && this->_x + i <= BOARD_MAX
// 		&& pieces[this->_y + i][this->_x + i]->getColor() != this->_color)
// 		moves->push(this->_x + i, this->_y + i, pieces[this->_y + i][this->_x + i]);

// 	for (i = 1; static_cast<int>(this->_y) - i >= 0 && static_cast<int>(this->_x) - i >=0
// 		&& !pieces[this->_y - i][this->_x - i]; i++)
// 		moves->push(this->_x - i, this->_y - i);
// 	if (static_cast<int>(this->_y) - i >= 0 && static_cast<int>(this->_x) - i >=0
// 		&& pieces[this->_y - i][this->_x - i]->getColor() != this->_color)
// 		moves->push(this->_x - i, this->_y - i, pieces[this->_y - i][this->_x - i]);

// 	for (i = 1; static_cast<int>(this->_y) - i >= 0 && this->_x + i <= BOARD_MAX
// 		&& !pieces[this->_y - i][this->_x + i]; i++)
// 		moves->push(this->_x + i, this->_y - i);
// 	if (static_cast<int>(this->_y) - i >= 0 && this->_x + i <= BOARD_MAX
// 		&& pieces[this->_y - i][this->_x + i]->getColor() != this->_color)
// 		moves->push(this->_x + i, this->_y - i, pieces[this->_y - i][this->_x + i]);

// 	for (i = 1; this->_y + i <= BOARD_MAX && static_cast<int>(this->_x) - i >=0
// 		&& !pieces[this->_y + i][this->_x - i]; i++)
// 		moves->push(this->_x - i, this->_y + i);
// 	if (this->_y + i <= BOARD_MAX && static_cast<int>(this->_x) - i >=0
// 		&& pieces[this->_y + i][this->_x - i]->getColor() != this->_color)
// 		moves->push(this->_x - i, this->_y + i, pieces[this->_y + i][this->_x - i]);
// 	return moves;
// }
