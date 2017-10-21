/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:31:09 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 01:52:29 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pawn.hpp"

int main() {
    Pawn    pawn(0, WHITE);
    std::vector<Move> moves;
    std::vector<APiece*> pieces;

    std::cout << pawn << std::endl;
    moves = pawn.getMoving(pieces, 1);
    for (std::vector<Move>::iterator it = moves.begin(); it != moves.end(); it++) {
        std::cout << it->x << " " << it->y << std::endl;
    }
    return 0;
}
