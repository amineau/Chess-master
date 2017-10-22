/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/23 00:18:40 by amineau          ###   ########.fr       */
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

	// std::cout <<board<<std::endl;
	std::vector<APiece*>&	pieces = board.getBoard();
	board.getPiece(0, 1)->setPosition(1, 2 ,1);
	std::vector<Move> &		moves = pieces.front()->getMoving(pieces, 1);
	displayMoves(moves);
	std::cout << *moves.front().piece << std::endl;
	delete &moves;
	return 0;
}
