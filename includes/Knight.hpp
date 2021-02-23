/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:52 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece {

public:
	Knight();
	Knight(bool isWhite);
	Knight(Knight const&);
	~Knight();

	Knight& operator=(Knight const&);

	bool			   canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(const GameStatus* gameStatus, const Spot* start) const;
};

#endif
