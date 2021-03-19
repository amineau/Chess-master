/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:07:23 by amineau          ###   ########.fr       */
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
	: _isLoad(false)
{
	return;
}

Board::Board(Board const& src)
{
	*this = src;
	return;
}

Board::~Board()
{
	return;
}

/* Members functions */

/* Accessors */

Spot* Board::getSpot(size_t x, size_t y) const
{
	if (x > 7 || y > 7)
		throw Board::IndexOutOfBoardException();
	return const_cast<Spot*>(&_spots[x][y]);
}

Spot* Board::getSpot(const std::string& spot) const
{
	if (spot.length() != 2)
		throw Board::IndexOutOfBoardException();
	return getSpot(spot[0] - 'a', spot[1] - '1');
}

void Board::raiseOnInvalidKingNumber() const
{
	Piece* piece;
	size_t kingWhite = 0;
	size_t kingBlack = 0;

	for (size_t y = 0; y < 8; y++) {
		for (size_t x = 0; x < 8; x++) {
			piece = getSpot(x, y)->getPiece();
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

bool Board::loadFen(const std::string& fen)
{
	short		x = 0;
	short		y = 7;
	int			i = 0;
	char		fenLower;
	std::string availableLowerChar("kqbnrp");

	if (_isLoad) {
		std::cout << "Please call GameStatus::clear before load" << std::endl;
		exit(EXIT_FAILURE);
	}
	while (fen[i]) {
		fenLower = tolower(fen[i]);
		if (x > 8 || y < 0)
			return false;
		if ('1' <= fen[i] && fen[i] <= '8' && (!fen[i] || !('1' <= fen[i + 1] && fen[i + 1] <= '8'))) {
			for (int j = '1'; j <= fen[i]; j++) {
				_spots[x][y] = Spot(x, y);
				x++;
			}
		} else if (availableLowerChar.find(fenLower) != std::string::npos) {
			if (fenLower == 'k')
				_spots[x][y] = Spot(x, y, new King(isupper(fen[i])));
			else if (fenLower == 'q')
				_spots[x][y] = Spot(x, y, new Queen(isupper(fen[i])));
			else if (fenLower == 'b')
				_spots[x][y] = Spot(x, y, new Bishop(isupper(fen[i])));
			else if (fenLower == 'n')
				_spots[x][y] = Spot(x, y, new Knight(isupper(fen[i])));
			else if (fenLower == 'r')
				_spots[x][y] = Spot(x, y, new Rook(isupper(fen[i])));
			else if (fenLower == 'p')
				_spots[x][y] = Spot(x, y, new Pawn(isupper(fen[i])));
			x++;
		} else if (fen[i] == '/') {
			if (x != 8)
				return false;
			x = 0;
			y--;
		} else
			return false;
		i++;
	}
	if (x != 8 && y != 1)
		return false;
	_isLoad = true;
	return true;
}

const std::string Board::exportFen() const
{
	Piece*			  piece;
	short			  numberEmptySpot;
	std::stringstream ss;

	for (int y = 7; y >= 0; --y) {
		numberEmptySpot = 0;
		for (int x = 0; x <= 7; ++x) {
			piece = this->getSpot(x, y)->getPiece();
			if (piece != NULL) {
				if (numberEmptySpot) {
					ss << numberEmptySpot;
					numberEmptySpot = 0;
				}
				ss << *piece;
			} else {
				numberEmptySpot++;
			}
		}
		if (numberEmptySpot)
			ss << numberEmptySpot;
		if (y != 0)
			ss << '/';
	}
	return ss.str();
}

/* Operator Overload */

Board& Board::operator=(Board const& rhs)
{
	// Piece* piece;
	if (this != &rhs) {
		this->_isLoad = rhs._isLoad;
		if (_isLoad)
			for (size_t y = 0; y < 8; y++)
				for (size_t x = 0; x < 8; x++)
					this->_spots[x][y] = rhs._spots[x][y];
		// piece = rhs._spots[x][y]->getPiece();
		// if (piece) {
		// 	// TODO: Pointer of function
		// 	if (piece->getType() == KING)
		// 		this->_spots[x][y] = new Spot(x, y, new King(dynamic_cast<King const&>(*rhs._spots[x][y]->getPiece())));
		// 	if (piece->getType() == QUEEN)
		// 		this->_spots[x][y] = new Spot(x, y, new Queen(dynamic_cast<Queen const&>(*rhs._spots[x][y]->getPiece())));
		// 	if (piece->getType() == BISHOP)
		// 		this->_spots[x][y] = new Spot(x, y, new Bishop(dynamic_cast<Bishop const&>(*rhs._spots[x][y]->getPiece())));
		// 	if (piece->getType() == KNIGHT)
		// 		this->_spots[x][y] = new Spot(x, y, new Knight(dynamic_cast<Knight const&>(*rhs._spots[x][y]->getPiece())));
		// 	if (piece->getType() == ROOK)
		// 		this->_spots[x][y] = new Spot(x, y, new Rook(dynamic_cast<Rook const&>(*rhs._spots[x][y]->getPiece())));
		// 	if (piece->getType() == PAWN)
		// 		this->_spots[x][y] = new Spot(x, y, new Pawn(dynamic_cast<Pawn const&>(*rhs._spots[x][y]->getPiece())));

		// } else
		// 	this->_spots[x][y] = new Spot(x, y);
		// 	}
		// }
	}
	return *this;
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
