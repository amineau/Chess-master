/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnPassantMove.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:42:54 by amineau           #+#    #+#             */
/*   Updated: 2021/05/14 23:32:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENPASSANTMOVE_HPP
#define ENPASSANTMOVE_HPP

#include "GameStatus.hpp"
#include "Move.hpp"

class EnPassantMove : public Move {

public:
	EnPassantMove();
	EnPassantMove(GameStatus*, Spot* start, Spot* end);
	EnPassantMove(EnPassantMove const&);
	~EnPassantMove();

	bool			  execute();
	const std::string getRepr() const;
	EnPassantMove*	  clone() const;

	EnPassantMove& operator=(EnPassantMove const&);

private:
	bool isLegal() const;

	Spot* _spotPieceKilled;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif