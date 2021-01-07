/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 14:39:32 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public virtual Piece {

public:
	Pawn();
	Pawn(bool isWhite);
	Pawn(Pawn const&);
	~Pawn();

	Pawn& operator=(Pawn const&);

	bool			   canMoves(Board* board, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(Board* board, Spot* start) const;
};

#endif
