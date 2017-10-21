/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2017/10/22 01:04:56 by amineau          ###   ########.fr       */
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

std::vector<APiece*> &	Board::getPieces() const {
	return _pieces;
}

/* Operator Overload */

std::ostream &	operator<<( std::ostream & o, Board const & i ) {
	std::vector<APiece*> & pieces = i.getPieces();

	for (std::vector<APiece*>::iterator it = pieces.begin(); it != pieces.end(); it++) {
		o << **it << std::endl;
	}
	return o;
}
