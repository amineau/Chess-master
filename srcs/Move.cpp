/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:37:38 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 19:51:55 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Move.hpp"

Move::Move(size_t x, size_t y, APiece * piece)
    : x(x)
    , y(y)
    , piece(piece)
{
    if (this->x > BOARD_MAX || this->y > BOARD_MAX)
        throw Move::MoveOutSidePositionException();
}

Move::Move( Move const & src ) {
    *this = src;
    return;
}

Move::~Move() {
    return;
}

Move &	Move::operator=( Move const & rhs ) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
        this->piece = rhs.piece;
    }
    return *this;
}

/* Exception */

char const *                Move::MoveOutSidePositionException::what() const throw() {
    return "Position is outside";
}
