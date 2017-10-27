/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:22:39 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.hpp"

int main() {
	Board board;

	std::vector<std::vector<APiece*> > const &	pieces = board.getBoard();
	Move &	moves = pieces[0][4]->getMoves();
	std::cout << moves <<std::endl;

	moves = pieces[1][4]->getMoves();
	board.moving(moves.getDestination(3, 4));
	moves = pieces[3][4]->getMoves();
	board.moving(moves.getDestination(4, 4));

	moves = pieces[6][3]->getMoves();
	board.moving(moves.getDestination(4, 3));

	moves = pieces[4][4]->getMoves();
	std::cout << moves <<std::endl;
	std::cout <<board<<std::endl;
	board.moving(moves.getDestination(5, 3));
	
	std::cout <<board<<std::endl;
	


	// delete &moves;
	return 0;
}
