/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:41:23 by amineau           #+#    #+#             */
/*   Updated: 2017/10/29 02:11:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_HPP
#define PIECE_HPP

#include "Board.hpp"
#include "Spot.hpp"
#include "utils.hpp"
#include <map>
#include <vector>

enum e_type {
	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN
};

typedef enum e_type t_type;

static std::map<int, const char*> pieceRepr = {
	{ KING, "\u265A" },
	{ QUEEN, "\u265B" },
	{ ROOK, "\u265C" },
	{ BISHOP, "\u265D" },
	{ KNIGHT, "\u265E" },
	{ PAWN, "\u265F" }
};

static std::map<const char, int> pieceChar = {
	{ 'K', KING },
	{ 'Q', QUEEN },
	{ 'R', ROOK },
	{ 'B', BISHOP },
	{ 'N', KNIGHT },
	{ 'P', PAWN }
};

class Piece {

public:
	Piece();
	Piece(t_type type);
	Piece(t_type type, bool isWhite);
	Piece(Piece const&);
	virtual ~Piece();

	Piece& operator=(Piece const&);

	bool		isWhite() const;
	void		setIsWhite(bool);
	t_type		getType() const;
	bool		isKilled() const;
	void		killed();
	const char* getRepr() const;
	bool virtual canMoves(Board* board, Spot* start, Spot* end) const;
	std::vector<Spot*> virtual validSpots(Board* board, Spot* start) const = 0;

protected:
	bool   _isWhite;
	t_type _type;
	bool   _isKilled;
};

std::ostream& operator<<(std::ostream& o, Piece const& i);

#endif
