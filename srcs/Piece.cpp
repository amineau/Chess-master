/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:49:45 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:21:29 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Piece.hpp"

Piece::Piece() {
	return;
}

Piece::Piece( bool isWhite )
	: _isWhite(isWhite)
	, _isKilled(false)
{
	return;
}

Piece::Piece( Piece const & src ) {
	*this = src;
	return;
}

Piece::~Piece() {
	return;
}

Piece &	Piece::operator=( Piece const & rhs ) {
	if (this != &rhs) {
		this->_isKilled = rhs._isKilled;
		this->_isWhite = rhs._isWhite;
		this->_type = rhs._type;
	}
	return *this;
}

/* Accessors */

bool			Piece::isWhite() const {
	return this->_isWhite;
}

t_type const &	Piece::getType() const {
	return this->_type;
}

/* Members functions */

bool 			Piece::isKilled() const {
	return this->_isKilled;
}

void			Piece::killed() {
	this->_isKilled = true;
}


bool			Piece::canMoves(Board board, Spot start, Spot end) const {
	if (start == end) return false;
	if (end.getPiece()->isWhite() == this->isWhite()) return false;
	return true;
}

/* Operator Overload */

std::ostream &	operator<<( std::ostream & o, Piece const & i ) {
	o << type[i.getType()];
	return o;
}
