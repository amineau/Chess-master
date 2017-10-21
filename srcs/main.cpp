/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 03:19:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"
#include "Rook.hpp"

int main() {
    Pawn    pawn(0, WHITE);
    Rook    rook0W(0, WHITE);
    Rook    rook1W(1, WHITE);
    Rook    rook0B(0, BLACK);
    Rook    rook1B(1, BLACK);
    std::vector<Move> moves;
    std::vector<APiece> pieces;

	// pieces.push_back(pawn);
	// pieces.push_back(rook0W);
	// pieces.push_back(rook1W);
	// pieces.push_back(rook0B);
	// pieces.push_back(rook1B);
    // std::cout << pawn << std::endl;
    std::cout << rook0W << std::endl;
    moves = rook0W.getMoving(pieces, 1);
    for (std::vector<Move>::iterator it = moves.begin(); it != moves.end(); it++) {
        std::cout << it->x << " " << it->y << " " << it->piece << std::endl;
	}
	rook0W.setPosition(5, 5, 5);
    moves = rook0W.getMoving(pieces, 1);
	
	for (std::vector<Move>::iterator it = moves.begin(); it != moves.end(); it++) {
        std::cout << it->x << " " << it->y << " " << it->piece << std::endl;
	}
	return 0;
}
