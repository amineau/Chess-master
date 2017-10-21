/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 20:47:41 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.hpp"

Board::Board()
	: _pieces(*(new std::vector<APiece*>()))
{
	this->_initPawns();
	this->_initRooks();
	return;
}

Board::Board( Board const & src )
	: _pieces(*(new std::vector<APiece*>()))
{
	*this = src;
	return;
}

Board::~Board() {
	return;
}

Board &	Board::operator=( Board const & rhs ) {
	if (this != &rhs) {
		this->_pieces = rhs._pieces;
	}
	return *this;
}

/* Members functions */

void	Board::_initPawns() {
	for (size_t color = 0; color <= 1; color++) {
		for (size_t i = 0; i <= BOARD_MAX; i++) {
			this->_pieces.push_back(new Pawn(i, static_cast<t_color>(color)));
		}		
	}
}

void	Board::_initRooks() {
	for (size_t color = 0; color <= 1; color++) {
		for (size_t i = 0; i <= 1; i++) {
			this->_pieces.push_back(new Rook(i, static_cast<t_color>(color)));
		}		
	}
}

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
