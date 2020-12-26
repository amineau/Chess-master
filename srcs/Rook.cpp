/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:10:56 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rook.hpp"

Rook::Rook()
	: Piece()
	, _type(ROOK)
{
	return;
}

Rook::Rook(bool isWhite)
	: Piece(isWhite)
	, _type(ROOK)
{
	return;
}

Rook::Rook(Rook const& src)
	: Piece()
{
	*this = src;
	return;
}

Rook::~Rook()
{
	return;
}

int sgn(int valeur)
{
	if (valeur < 0)
		return -1;
	if (valeur == 0)
		return 0;
	return 1;
}

bool Rook::canMoves(Board board, Spot start, Spot end) const
{
	int i;
	int distX = abs(end.getX() - start.getX());
	int distY = abs(end.getY() - start.getY());
	int signX = sgn(end.getX() - start.getX());
	int signY = sgn(end.getY() - start.getY());

	if (!Piece::canMoves(board, start, end))
		return false;

	if (distX * distY != 0) {
		return false;
	}

	for (i = 1; start.getX() + i * signX != end.getX(); i++) {
		if (board.getBox(start.getX() + i * signX, start.getY())->getPiece() != NULL) {
			return false;
		}
	}

	for (i = 1; start.getY() + i * signY != end.getY(); i++) {
		if (board.getBox(start.getX(), start.getY() + i * signX)->getPiece() != NULL) {
			return false;
		}
	}

	return true;
}

// Move *	Rook::calculMoves( std::vector<std::vector<Piece*> > const & pieces, size_t ) {
// 	int x;
// 	int y;
// 	Move *	moves = new Move(this);

// 	for (x = this->_x + 1; x <= BOARD_MAX && !pieces[this->_y][x];x++)
// 		moves->push(x, this->_y);
// 	if (x <= BOARD_MAX && pieces[this->_y][x]->getColor() != this->_color)
// 		moves->push(x, this->_y, pieces[this->_y][x]);

// 	for (x = this->_x - 1; x >= 0 && !pieces[this->_y][x];x--)
// 		moves->push(x, this->_y);
// 	if (x >= 0 && pieces[this->_y][x]->getColor() != this->_color)
// 		moves->push(x, this->_y, pieces[this->_y][x]);

// 	for (y = this->_y + 1; y <= BOARD_MAX && !pieces[y][this->_x];y++)
// 		moves->push(this->_x, y);
// 	if (y <= BOARD_MAX && pieces[y][this->_x]->getColor() != this->_color)
// 		moves->push(this->_x, y, pieces[y][this->_x]);

// 	for (y = this->_y - 1; y >= 0 && !pieces[y][this->_x];y--)
// 		moves->push(this->_x, y);
// 	if (y >= 0 && pieces[y][this->_x]->getColor() != this->_color)
// 		moves->push(this->_x, y, pieces[y][this->_x]);
// 	return moves;
// }
