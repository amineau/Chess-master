/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/01/05 19:24:31 by amineau          ###   ########.fr       */
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

	bool			   canMoves(Board* board, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(Board* board, Spot* start) const;
};

#endif
