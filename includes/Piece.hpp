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

enum e_type {
	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN
};

typedef enum e_type t_type;

static std::pair<int, const char*> map_type[] = {
	std::make_pair(KING, "\u265A"),
	std::make_pair(QUEEN, "\u265B"),
	std::make_pair(ROOK, "\u265C"),
	std::make_pair(BISHOP, "\u265D"),
	std::make_pair(KNIGHT, "\u265E"),
	std::make_pair(PAWN, "\u265F")
};

static std::map<int, const char*> type(map_type,
	map_type + sizeof map_type / sizeof map_type[0]);

class Piece {

public:
	Piece();
	Piece(t_type type, bool isWhite);
	Piece(Piece const&);
	virtual ~Piece();

	Piece& operator=(Piece const&);

	bool   isWhite() const;
	t_type getType() const;
	bool   isKilled() const;
	void   killed();
	bool   canMoves(Board board, Spot start, Spot end) const;

protected:
	bool   _isWhite;
	t_type _type;
	bool   _isKilled;
};

std::ostream& operator<<(std::ostream& o, Piece const& i);

#endif
