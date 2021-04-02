/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:43:39 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_HPP
#define PIECE_HPP

#include "GameStatus.hpp"
#include "Spot.hpp"
#include "utils.hpp"
#include <iostream>
#include <map>
#include <vector>

// class GameStatus;

enum e_type {
	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN
};

typedef enum e_type t_type;

static std::map<int, const char> pieceRepr = {
	// { KING, "\u265A" },
	// { QUEEN, "\u265B" },
	// { ROOK, "\u265C" },
	// { BISHOP, "\u265D" },
	// { KNIGHT, "\u265E" },
	// { PAWN, "\u265F" }
	{ KING, 'k' },
	{ QUEEN, 'q' },
	{ ROOK, 'r' },
	{ BISHOP, 'b' },
	{ KNIGHT, 'n' },
	{ PAWN, 'p' }
};

class Piece {

public:
	Piece();
	Piece(t_type type);
	Piece(t_type type, bool isWhite);
	Piece(Piece const&);
	virtual ~Piece();

	Piece& operator=(Piece const&);

	bool   isWhite() const;
	void   setIsWhite(bool);
	t_type getType() const;
	bool   isKilled() const;
	void   killed();
	bool virtual canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	std::vector<Spot*> virtual validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
	std::vector<Spot*> validSpots(const GameStatus* gameStatus, const Spot* start) const;

	Piece* clone() const;

protected:
	bool   _isWhite;
	t_type _type;
	bool   _isKilled;
};

std::ostream& operator<<(std::ostream& o, Piece const& i);

#endif
