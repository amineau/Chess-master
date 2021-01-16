/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/01/08 19:13:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public virtual Piece {

public:
	Bishop();
	Bishop(bool isWhite);
	Bishop(Bishop const&);
	~Bishop();

	Bishop& operator=(Bishop const&);

	bool			   canMoves(Board* board, Spot* start, Spot* end) const;
	std::vector<Spot*> validSpots(Board* board, Spot* start) const;
};

#endif
