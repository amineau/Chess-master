/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:09:58 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:22:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "King.hpp"

King::King()
	: Piece()
	, _type(KING)
	, _castlingDone(false)
{
	return;
}

King::King( bool isWhite )
	: Piece(isWhite)
	, _type(KING)
	, _castlingDone(false)
{
	return;
}

King::King( King const & src )
	: Piece()
{
	*this = src;
	return;
}

King::~King() {
	return;
}

bool	King::isCastlingDone() const {
	return this->_castlingDone;
}

void	King::setCastlingDone( bool castlingDone ) {
	this->_castlingDone = castlingDone;
}

King &	King::operator=( King const & rhs ) {
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_castlingDone = rhs._castlingDone;
	}
	return *this;
}

bool	King::canMoves(Board board, Spot start, Spot end) const {
	int distX = abs(end.getX() - start.getX());
	int distY = abs(end.getY() - start.getY());

	if (!Piece::canMoves(board, start, end)) return false;

	return distX + distY == 1 || distX * distY == 1;
}

// Move *	King::calculMoves( std::vector<std::vector<Piece*> > const & pieces, size_t ) {
// 	int x;
// 	int y;
// 	Move *	moves = new Move(this);

// 	for (int i = -1; i <= 1; i++) {
// 		x = this->_x + i;
// 		if (x >= 0 && x <= BOARD_MAX) {
// 			for (int j = -1; j <= 1; j++) {
// 				y = this->_y + j;
// 				if (y >= 0 && y <= BOARD_MAX && (i || j)) {
// 					if (pieces[y][x] && pieces[y][x]->getColor() != this->_color)
// 						moves->push(x, y, pieces[y][x]);
// 					else if (!pieces[y][x])
// 						moves->push(x, y);
// 				}
// 			}
// 		}
// 	}
// 	// Rook
// 	if (!this->_last_move) {
// 		for (int i = 1; this->_x - i == 0 || (this->_x - i > 0 && !pieces[this->_y][this->_x - i]); i++) {
// 			// check echec
// 			if (this->_x - i == 0 && pieces[this->_y][this->_x - i]->getLastMove() == 0)
// 				moves->push(this->_x - 2, this->_y);
// 		}
// 		for (int i = 1; this->_x + i == BOARD_MAX || (this->_x + i < BOARD_MAX && !pieces[this->_y][this->_x + i]); i++) {
// 			// check echec
// 			if (this->_x + i == BOARD_MAX && pieces[this->_y][this->_x + i]->getLastMove() == 0)
// 				moves->push(this->_x + 2, this->_y);
// 		}
// 	}
// 	return moves;
// }
