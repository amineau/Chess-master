/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:43:39 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 23:39:01 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_HPP
#define PIECE_HPP

#include "utils.hpp"
#include <iostream>
#include <map>
#include <vector>

class Spot;
class GameStatus;

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
	{ KING, 'K' },
	{ QUEEN, 'Q' },
	{ ROOK, 'R' },
	{ BISHOP, 'B' },
	{ KNIGHT, 'N' },
	{ PAWN, 'P' },
};

static std::map<int, const char*> pieceUnicodeRepr = {
	{ KING, "\u265A" },
	{ QUEEN, "\u265B" },
	{ ROOK, "\u265C" },
	{ BISHOP, "\u265D" },
	{ KNIGHT, "\u265E" },
	{ PAWN, "\u265F" },
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
	t_type getType() const;
	bool   isKilled() const;
	void   killed();
	bool virtual canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool virtual canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	std::vector<Spot*> virtual validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;
	std::vector<Spot*> validSpots(const GameStatus* gameStatus, const Spot* start) const;
	char			   getRepr() const;
	const char*		   getUnicodeRepr() const;

	Piece* clone() const;

protected:
	bool   _isWhite;
	t_type _type;
	bool   _isKilled;
};

std::ostream& operator<<(std::ostream& o, Piece const& i);

#endif
