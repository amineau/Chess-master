/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:09:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "Spot.hpp"
#include <sstream>
#include <vector>

class Pieces;

class Board {

public:
	Board();
	Board(Board const&);
	~Board();

	Spot* getBox(size_t x, size_t y);
	void  initialize();

	Board& operator=(Board const&);

	class IndexOutOfBoardException : public std::exception {
	public:
		virtual char const* what() const throw();
	};

private:
	Spot _boxes[8][8];
};

std::ostream& operator<<(std::ostream& o, Board const& i);

#endif
