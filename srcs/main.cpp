/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/24 02:25:45 by amineau          ###   ########.fr       */
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
	std::vector<std::vector<APiece*> > const &	pieces = board.getBoard();
	std::vector<Move> &		moves = pieces[1][0]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[1][0], moves.front());
	std::cout <<board<<std::endl;
	
	moves = pieces[2][0]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[2][0], moves.front());
	std::cout <<board<<std::endl;
	
	moves = pieces[0][0]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[0][0], moves.back());
	std::cout <<board<<std::endl;

	moves = pieces[2][0]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[2][0], moves[6]);
	std::cout <<board<<std::endl;

	moves = pieces[2][7]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[2][7], moves.back());
	std::cout <<board<<std::endl;

	// std::cout << *moves.front().piece << std::endl;
	// delete &moves;
	return 0;
}
