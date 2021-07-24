/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 18:23:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
#define PAWN_HPP

#include "GameStatus.hpp"
#include "Piece.hpp"
#include "Spot.hpp"

class Pawn : public Piece {

public:
	Pawn();
	Pawn(bool isWhite);
	Pawn(Pawn const&);
	~Pawn();

	Pawn& operator=(Pawn const&);

	bool			   canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool			   canMovesEnPassant(GameStatus* gameStatus, Spot* start, Spot* end, Spot* spotPieceKilled) const;
	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
};

#endif
