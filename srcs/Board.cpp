/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2017/10/23 00:27:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.hpp"

Board::Board()
	: _pieces(*(new std::vector<APiece*>()))
{
	this->_init(Rook());
	this->_init(Pawn());
	return;
}

Board::Board( Board const & src )
	: _pieces(*(new std::vector<APiece*>()))
{
	*this = src;
	return;
}

Board::~Board() {
	std::vector<APiece*>::iterator it;
	for (it = this->_pieces.begin(); it != this->_pieces.end(); it++)
		delete &(**it);
	delete &this->_pieces;
	return;
}

Board &	Board::operator=( Board const & rhs ) {
	if (this != &rhs) {
		this->_pieces = rhs._pieces;
	}
	return *this;
}

/* Members functions */



/* Accessors */

std::vector<APiece*> &	Board::getBoard() const {
	return _pieces;
}

APiece &				Board::getPiece(size_t x, size_t y) const {
	for (std::vector<APiece*>::iterator it = this->_pieces.begin(); it != this->_pieces.end(); it++)
		if ((*it)->getX() == x && (*it)->getY() == y)
			return **it;
	throw Board::UnkownPiecePositionException();
}


/* Operator Overload */

std::ostream &	operator<<( std::ostream & o, Board const & i ) {
	std::vector<APiece*> & pieces = i.getBoard();

	for (std::vector<APiece*>::iterator it = pieces.begin(); it != pieces.end(); it++) {
		o << **it << std::endl;
	}
	return o;
}

/* Exception */

char const *	Board::UnkownPiecePositionException::what() const throw() {
    return "There is no piece on the target position";
}
