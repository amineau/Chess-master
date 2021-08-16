/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnPassantMove.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:42:54 by amineau           #+#    #+#             */
/*   Updated: 2021/08/16 14:31:54 by amineau          ###   ########.fr       */
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
	bool		   isLegal() const;
	EnPassantMove* clone() const;

	EnPassantMove& operator=(EnPassantMove const&);

private:
	void generateRepr();

	Spot* _spotPieceKilled;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif