/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:49:45 by amineau           #+#    #+#             */
/*   Updated: 2017/10/22 00:57:25 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "APiece.hpp"

APiece::APiece() {
    return;
}

APiece::APiece( t_type type )
    : _type(type)
{
    return;
}

APiece::APiece( t_type type, e_color color, size_t x, size_t y )
    : _color(color)
    , _x(x)
    , _y(y)
    , _type(type)
{
    if (this->_x > BOARD_MAX || this->_y > BOARD_MAX)
        throw APiece::PieceOutSidePositionException();
    return;
}

APiece::APiece( APiece const & src ) {
    *this = src;
    return;
}

APiece::~APiece() {
    return;
}

APiece &	APiece::operator=( APiece const & rhs ) {
    if (this != &rhs) {
        this->_x = rhs._x;
        this->_y = rhs._y;
        this->_type = rhs._type;
        this->_color = rhs._color;
    }
    return *this;
}

/* Accessors */

size_t               APiece::getX() const {
    return this->_x;
}

size_t               APiece::getY() const {
    return this->_y;
}

t_color const &            APiece::getColor() const {
    return this->_color;
}

t_type const &              APiece::getType() const {
    return this->_type;
}

void                        APiece::setPosition(size_t x, size_t y, size_t round) {
    if (x > 7 || y > 7)
        throw APiece::PieceOutSidePositionException();
    this->_x = x;
    this->_y = y;
    this->_last_move = round;
}

char                        APiece::getXRepresentation() const {
    return this->_x + 'a';
}
size_t                APiece::getYRepresentation() const {
    return this->_y + 1;
}

/* Exception */

char const *                APiece::PieceOutSidePositionException::what() const throw() {
    return "Position is outside";
}

/* Operator Overload */

std::ostream &              operator<<( std::ostream & o, APiece const & i ) {
    o << i.getType() << " " << i.getXRepresentation() << i.getYRepresentation();
    return o;
}
