/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/25 21:35:27 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::vector<Move> &		moves = pieces[1][3]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[1][3], moves.back());
	std::cout <<board<<std::endl;


	moves = pieces[0][2]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[0][2], moves[2]);
	std::cout <<board<<std::endl;
	
	moves = pieces[0][1]->getMoving(pieces, 0);
	displayMoves(moves);
	board.moving(pieces[0][1], moves[2]);
	std::cout <<board<<std::endl;
	// std::cout << *moves.front().piece << std::endl;
	// delete &moves;
	return 0;
}
