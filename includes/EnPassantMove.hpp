/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnPassantMove.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:42:54 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:09:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENPASSANTMOVE_HPP
#define ENPASSANTMOVE_HPP

#include "GameStatus.hpp"
#include "Move.hpp"

class EnPassantMove : public Move {

public:
	EnPassantMove();
	EnPassantMove(GameStatus*, Player*, Spot* start, Spot* end);
	EnPassantMove(EnPassantMove const&);
	~EnPassantMove();

	bool			  isLegal() const;
	void			  execute();
	const std::string getRepr() const;
	EnPassantMove*	  clone() const;

	EnPassantMove& operator=(EnPassantMove const&);

private:
	Spot* _spotPieceKilled;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif