/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2021/01/15 23:10:22 by amineau          ###   ########.fr       */
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
	// std::cout << "Constructor Board called" << std::endl;
	return;
}

Board::Board(Board const& src)
{
	// std::cout << "Constructor Board by REF called" << std::endl;
	*this = src;
	return;
}

Board::~Board()
{
	// std::cout << "Deconstructor Board called" << std::endl;
	for (size_t y = 0; y < 8; y++) {
		for (size_t x = 0; x < 8; x++) {
			delete this->_boxes[x][y];
		}
	}

	return;
}

/* Members functions */

/* Accessors */

Spot* Board::getBox(size_t x, size_t y) const
{
	if (x > 7 || y > 7)
		throw Board::IndexOutOfBoardException();
	return this->_boxes[x][y];
}

void Board::setBox(size_t x, size_t y, Spot* spot)
{
	if (x > 7 || y > 7)
		throw Board::IndexOutOfBoardException();
	this->_boxes[x][y] = spot;
}

void Board::raiseOnInvalidKingNumber() const
{
	Piece* piece;
	size_t kingWhite = 0;
	size_t kingBlack = 0;

	for (size_t y = 0; y < 8; y++) {
		for (size_t x = 0; x < 8; x++) {
			piece = this->getBox(x, y)->getPiece();
			if (piece && piece->getType() == KING) {
				if (piece->isWhite())
					kingWhite++;
				else
					kingBlack++;
			}
		}
	}
	if (kingBlack != 1 || kingWhite != 1)
		throw Board::InvalidNumberOfKingException();
}

/* Operator Overload */

Board& Board::operator=(Board const& rhs)
{
	Piece* piece;
	if (this != &rhs) {
		for (size_t y = 0; y < 8; y++) {
			for (size_t x = 0; x < 8; x++) {
				piece = rhs._boxes[x][y]->getPiece();
				if (piece) {
					if (piece->getType() == KING)
						this->_boxes[x][y] = new Spot(x, y, new King(dynamic_cast<King const&>(*rhs._boxes[x][y]->getPiece())));
					if (piece->getType() == QUEEN)
						this->_boxes[x][y] = new Spot(x, y, new Queen(dynamic_cast<Queen const&>(*rhs._boxes[x][y]->getPiece())));
					if (piece->getType() == BISHOP)
						this->_boxes[x][y] = new Spot(x, y, new Bishop(dynamic_cast<Bishop const&>(*rhs._boxes[x][y]->getPiece())));
					if (piece->getType() == KNIGHT)
						this->_boxes[x][y] = new Spot(x, y, new Knight(dynamic_cast<Knight const&>(*rhs._boxes[x][y]->getPiece())));
					if (piece->getType() == ROOK)
						this->_boxes[x][y] = new Spot(x, y, new Rook(dynamic_cast<Rook const&>(*rhs._boxes[x][y]->getPiece())));
					if (piece->getType() == PAWN)
						this->_boxes[x][y] = new Spot(x, y, new Pawn(dynamic_cast<Pawn const&>(*rhs._boxes[x][y]->getPiece())));

				} else
					this->_boxes[x][y] = new Spot(x, y);
			}
		}
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

char const* Board::InvalidNumberOfKingException::what() const throw()
{
	return "There is not one King by player";
}
