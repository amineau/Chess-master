/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnPassantMove.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:42:54 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:33:22 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENPASSANTMOVE_HPP
#define ENPASSANTMOVE_HPP

#include "Actions/Move.hpp"
#include "Game/GameStatus.hpp"

class EnPassantMove : public Move {

public:
	EnPassantMove();
	EnPassantMove(GameStatus*, Spot* start, Spot* end);
	EnPassantMove(EnPassantMove const&);
	~EnPassantMove();

	bool		   execute();
	EnPassantMove* clone() const;

	EnPassantMove& operator=(EnPassantMove const&);

private:
	void generateRepr();
	bool isLegal() const;

	Spot* _spotPieceKilled;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif