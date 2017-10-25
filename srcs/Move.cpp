/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2017/10/26 01:15:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Move.hpp"

Move::Move( APiece * player )
	: _player(player)
{
	return;
}

Move::Move( Move const & src )
{
	*this = src;
	return;
}

Move::~Move() {
	return;
}

/* Accessors */
std::vector<Destination> const &	Move::getMoves() const {
	return this->_moves;
}

Destination const &					Move::getDestination(size_t y, size_t x) {
	std::vector<Destination>::iterator it;

	for (it = this->_moves.begin(); it != this->_moves.end(); it++)
		if (it->x == x && it->y == y)
			return *it;
	throw MoveDoesntExistException();
}

/* Members functions */

void	Move::push(size_t x, size_t y, APiece * target) {
	this->_moves.push_back(Destination(x, y, this->_player, target));
}

void	Move::push(size_t x, size_t y) {
	this->_moves.push_back(Destination(x, y, this->_player));
}

void	Move::push(Destination dest) {
	this->_moves.push_back(dest);
}

/* Operators Overload */

Move &	Move::operator=( Move const & rhs ) {
	if (this != &rhs) {
		this->_moves = rhs._moves;
		this->_player = rhs._player;
	}
	return *this;
}

Move &	Move::operator+( Move const & rhs ) {
	if (this != &rhs && &this->_player == &rhs._player) {
		for (std::vector<const Destination>::iterator it = rhs._moves.begin(); it != rhs._moves.end(); it++) {
			this->push(*it);
		}
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Move const & i ) {
	// std::vector<Destination>::iterator	it;
	for (std::vector<const Destination>::iterator it = i.getMoves().begin(); it != i.getMoves().end(); it++)
		o << it->x << " " << it->y << " " << it->getTarget() << std::endl;
	return o;
}

/* Exception */

char const *	Move::MoveDoesntExistException::what() const throw() {
	return "The destination is not possible";
}
