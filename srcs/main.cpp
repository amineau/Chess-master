/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/26 01:51:07 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.hpp"

int main() {
	Board board;

	std::vector<std::vector<APiece*> > const &	pieces = board.getBoard();
	Move &	moves = pieces[0][4]->getMoving(pieces, 0);
	std::cout << moves <<std::endl;
	// board.moving(moves.getDestination(3, 3));
	
	// moves = pieces[3][3]->getMoving(pieces, 0);
	// board.moving(moves.getDestination(4, 3));

	

	// moves = pieces[0][2]->getMoving(pieces, 0);
	// board.moving(moves.getDestination(2, 4));	

	// moves = pieces[0][1]->getMoving(pieces, 0);
	// board.moving(moves.getDestination(2, 2));

	// moves = pieces[2][2]->getMoving(pieces, 0);
	// std::cout << moves <<std::endl;
	// std::cout <<board<<std::endl;
	// board.moving(moves.getDestination(4, 1));
	
	// moves = pieces[4][1]->getMoving(pieces, 0);
	// std::cout <<moves<<std::endl;
	// board.moving(moves.getDestination(6, 2));
	
	// moves = pieces[0][3]->getMoving(pieces, 0);
	// std::cout << moves <<std::endl;
	// board.moving(moves.getDestination(3, 3));

	// moves = pieces[3][3]->getMoving(pieces, 0);
	// std::cout << moves <<std::endl;
	
	

	std::cout <<board<<std::endl;


	// delete &moves;
	return 0;
}
