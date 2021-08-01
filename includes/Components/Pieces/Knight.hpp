/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:32:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Components/Pieces/Piece.hpp"
#include "Components/Spot.hpp"
#include "Game/GameStatus.hpp"

class Knight : public Piece {

public:
	Knight();
	Knight(bool isWhite);
	Knight(Knight const&);
	~Knight();

	Knight& operator=(Knight const&);

	bool			   canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
};

#endif
