/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 15:23:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public virtual Piece {

public:
	Knight();
	Knight(bool isWhite);
	Knight(Knight const&);
	~Knight();

	Knight& operator=(Knight const&);

	bool			   canMoves(Board* board, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(Board* board, Spot* start) const;
};

#endif
