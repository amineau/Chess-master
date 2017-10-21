/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/22 01:35:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"
#include "Rook.hpp"
#include "Board.hpp"

void displayMoves(std::vector<Move> & moves) {
	std::vector<Move>::iterator	it;
	for (it = moves.begin(); it != moves.end(); it++)
		std::cout << it->x << " " << it->y << " " << it->piece << std::endl;
}

int main() {
	Board board;

	std::cout <<board<<std::endl;
	std::vector<APiece*>&	pieces = board.getPieces();
	std::vector<Move> &		moves = pieces.front()->getMoving(pieces, 2);
	displayMoves(moves);
	delete &moves;
	return 0;
}
