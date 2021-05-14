/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/05/15 00:07:19 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "GameStatus.hpp"
#include "Piece.hpp"
#include "Spot.hpp"

class Knight : public Piece {

public:
	Knight();
	Knight(bool isWhite);
	Knight(Knight const&);
	~Knight();

	Knight& operator=(Knight const&);

	bool			   canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
};

#endif
