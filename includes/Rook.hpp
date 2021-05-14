/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/05/15 00:07:02 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOK_HPP
#define ROOK_HPP

#include "GameStatus.hpp"
#include "Piece.hpp"
#include "Spot.hpp"

class Rook : public virtual Piece {

public:
	Rook();
	Rook(bool isWhite);
	Rook(Rook const&);
	~Rook();

	Rook& operator=(Rook const&);

	bool			   canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
};

#endif
