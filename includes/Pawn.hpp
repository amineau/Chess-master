/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:45 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece {

public:
	Pawn();
	Pawn(bool isWhite);
	Pawn(Pawn const&);
	~Pawn();

	Pawn& operator=(Pawn const&);

	bool			   canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const;
	bool			   canMovesEnPassant(GameStatus* gameStatus, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(GameStatus* gameStatus, Spot* start) const;
};

#endif
