/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:49:45 by amineau           #+#    #+#             */
/*   Updated: 2017/10/17 22:42:50 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "APiece.hpp"

APiece::APiece( t_type type, int x, int y )
    : _type(type)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
        throw APiece::OutSidePositionException();
    _position.x = x;
    _position.y = y;
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
        this->_position = rhs.getPosition();
        this->_player = rhs.getPlayer();
    }
    return *this;
}

/* Accessors */

t_coordinate                APiece::getPosition() const {
    return this->_position;
}

t_player                    APiece::getPlayer() const {
    return this->_player;
}

t_type                      APiece::getType() const {
    return this->_type;
}

std::vector<t_coodinate>    APiece::getMoving() const {
    return this->_moving;
}

void                        APiece::setPosition(t_coordinate const & coord) {
    if ( std::find(this->_moving.begin(), this->_moving.end(), coord) != this->_moving.end() )
        throw APiece::OutSidePositionException();
    this->_position = coord;
}

char                        APiece::getXrepresentation() const {
    return _position.x + 'a';
}
int                         APiece::getYrepresentation() const {
    return  _position.y + 1;
}

/* Exception */

char const * APiece::OutSidePositionException::what() const throw() {
    return "Position is outside";
}

/* Operator Overload */

std::ostream &   operator<<( std::ostream & o, APiece const & i ) {
    o << i.getXrepresentation() << i.getYrepresentation();
    return o;
}