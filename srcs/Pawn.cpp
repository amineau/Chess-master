/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:35:50 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:10:37 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"

Pawn::Pawn() { return; }

Pawn::Pawn(bool isWhite)
	: Piece(isWhite)
	, _type(PAWN)
{
	return;
}

Pawn::Pawn(Pawn const& src)
	: Piece()
{
	*this = src;
	return;
}

Pawn::~Pawn() { return; }

/* Members functions */

bool Pawn::canMoves(Board board, Spot start, Spot end) const
{
	bool isWhite = start.getPiece()->isWhite();
	int	 direction = isWhite ? 1 : -1;
	int	 deltaX = end.getX() - start.getX();
	int	 deltaY = end.getY() - start.getY();

	if (!Piece::canMoves(board, start, end))
		return false;
	if (end.getPiece() == NULL) {
		if (start.getX() != end.getX())
			return false;
		else if ((start.getY() == 1 && isWhite) || (start.getY() == 6 && !isWhite)) {
			if (deltaY != direction || deltaY != direction * 2)
				return false;
			if (deltaY == direction * 2 && board.getBox(start.getX(), start.getY() + direction)->getPiece() != NULL)
				return false;
		} else {
			if (deltaY != direction)
				return false;
		}
	} else {
		if (abs(deltaX) != 1 || deltaY != direction)
			return false;
	}
	return true;
}

/* Accessors */

// Move *	Pawn::calculMoves( std::vector<std::vector<Piece*> > const &
// pieces, size_t round ) { 	Move *	moves = new Move(this); 	Pawn *	pawn;
// 	int		x;
// 	int		direction = this->_color == WHITE ? 1 : -1;
// 	size_t	y_move = static_cast<int>(this->_y) + 1 * direction;

// 	(void)round;
// 	if (this->_x + 1 <= BOARD_MAX
// 		&& pieces[y_move][this->_x + 1]
// 		&& pieces[y_move][this->_x + 1]->getColor() != this->_color)
// 		moves->push(this->_x + 1, y_move, pieces[y_move][this->_x + 1]);
// 	if (static_cast<int>(this->_x) - 1 >= 0
// 		&& pieces[y_move][this->_x - 1]
// 		&& pieces[y_move][this->_x - 1]->getColor() != this->_color)
// 		moves->push(this->_x - 1, y_move, pieces[y_move][this->_x - 1]);

// 	// Moving list
// 	if (!pieces[y_move][this->_x]) {
// 		moves->push(this->_x, y_move);
// 		if (this->_y == static_cast<size_t>(this->_color) * 5 + 1
// 			&& !pieces[static_cast<int>(this->_y) + 2 *
// direction][this->_x]) 			moves->push(this->_x, static_cast<int>(this->_y) + 2 *
// direction);
// 	}

// 	// En Passant Capture
// 	if (static_cast<int>(this->_y) == 4 - this->_color)
// 		for (int i = -1; i <= 1; i += 2) {
// 			x = static_cast<int>(this->_x) + i;
// 			pawn = dynamic_cast<Pawn*>(pieces[this->_y][x]);
// 			if (x >= 0 && x <= BOARD_MAX && pawn
// 				&& pawn->getColor() != this->_color
// 				&& static_cast<int>(pawn->getLastY()) == pawn->getColor()
// * 5 + 1
// 				&& pawn->getLastMove() == round - 1)
// 				moves->push(x, 2 + pawn->getColor() * 3, pawn);
// 		}
// 	return moves;
// }
