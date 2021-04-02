/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Bishop.hpp"
#include "Rook.hpp"

class Queen : public Bishop, public Rook {

public:
	Queen();
	Queen(bool isWhite);
	Queen(Queen const&);
	~Queen();

	Queen& operator=(Queen const&);

	bool			   canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
};

#endif
