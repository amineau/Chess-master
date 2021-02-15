/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public virtual Piece {

public:
	Rook();
	Rook(bool isWhite);
	Rook(Rook const&);
	~Rook();

	Rook& operator=(Rook const&);

	bool			   canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(GameStatus* gameStatus, Spot* start) const;
};

#endif
