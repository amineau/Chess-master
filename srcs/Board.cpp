/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2021/01/04 19:20:35 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

Board::Board()
{
	this->initialize();
	return;
}

Board::Board(Board const& src)
{
	*this = src;
	return;
}

Board::~Board()
{
	// std::vector<Piece*>::iterator it;
	// for (it = this->_pieces.begin(); it != this->_pieces.end(); it++)
	// 	delete &(**it);
	// delete this->_board;

	return;
}

/* Members functions */

void Board::initialize()
{
	int x;
	int y;

	this->_boxes[0][0] = Spot(0, 0, new Rook(true));
	this->_boxes[1][0] = Spot(1, 0, new Knight(true));
	this->_boxes[2][0] = Spot(2, 0, new Bishop(true));
	this->_boxes[3][0] = Spot(3, 0, new Queen(true));
	this->_boxes[4][0] = Spot(4, 0, new King(true));
	this->_boxes[5][0] = Spot(5, 0, new Bishop(true));
	this->_boxes[6][0] = Spot(6, 0, new Knight(true));
	this->_boxes[7][0] = Spot(7, 0, new Rook(true));

	for (x = 0; x <= 7; x++) {
		this->_boxes[x][1] = Spot(x, 1, new Pawn(true));
	}

	this->_boxes[0][7] = Spot(0, 7, new Rook(false));
	this->_boxes[1][7] = Spot(1, 7, new Knight(false));
	this->_boxes[2][7] = Spot(2, 7, new Bishop(false));
	this->_boxes[3][7] = Spot(3, 7, new Queen(false));
	this->_boxes[4][7] = Spot(4, 7, new King(false));
	this->_boxes[5][7] = Spot(5, 7, new Bishop(false));
	this->_boxes[6][7] = Spot(6, 7, new Knight(false));
	this->_boxes[7][7] = Spot(7, 7, new Rook(false));

	for (x = 0; x <= 7; x++) {
		this->_boxes[x][6] = Spot(x, 6, new Pawn(false));
	}

	for (x = 0; x < 8; x++) {
		for (y = 2; y < 6; y++) {
			this->_boxes[x][y] = Spot(x, y);
		}
	}
}

/* Accessors */

Spot* Board::getBox(size_t x, size_t y) const
{
	if (x >= 8 || y >= 8)
		throw Board::IndexOutOfBoardException();
	return const_cast<Spot*>(&this->_boxes[x][y]);
}

/* Operator Overload */

Board& Board::operator=(Board const& rhs)
{
	if (this != &rhs) {
		// this->_boxes = rhs._boxes;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Board const& i)
{
	Piece* piece;

	o << "\033[38;5;232;48;5;215m                    \033[0m" << std::endl;
	for (int y = 7; y >= 0; --y) {
		o << "\033[38;5;232;48;5;215m" << y + 1 << " ";
		for (int x = 0; x <= 7; ++x) {
			if ((y + x) % 2)
				o << "\033[48;5;255m";
			else
				o << "\033[48;5;75m";
			piece = i.getBox(x, y)->getPiece();
			if (piece != NULL) {
				if (piece->isWhite())
					o << "\033[1;38;5;22m";
				else
					o << "\033[1;38;5;232m";
				o << *piece << " ";
			} else
				o << "  ";
		}
		o << "\033[38;5;232;48;5;215m  \033[0m" << std::endl;
	}
	o << "\033[38;5;232;48;5;215m  a b c d e f g h   \033[0m" << std::endl;
	return o;
}

/* Exception */

char const* Board::IndexOutOfBoardException::what() const throw()
{
	return "x and y must be between 0 and 7";
}