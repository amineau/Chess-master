/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:49:45 by amineau           #+#    #+#             */
/*   Updated: 2017/10/18 00:01:53 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "APiece.hpp"

APiece::APiece( t_type type, int x, int y )
    : _type(type)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
        throw APiece::OutSidePositionException();
    this->_position.x = x;
    this->_position.y = y;
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

t_coordinate const &        APiece::getPosition() const {
    return this->_position;
}

t_player const &            APiece::getPlayer() const {
    return this->_player;
}

t_type const &              APiece::getType() const {
    return this->_type;
}

void                        APiece::setPosition(t_coordinate const & coord) {
    if ( coord.x < 0 || coord.x > 7 || coord.y < 0 || coord.y > 7 )
        throw APiece::OutSidePositionException();
    this->_position = coord;
}

char                        APiece::getXRepresentation() const {
    return _position.x + 'a';
}
int                         APiece::getYRepresentation() const {
    return  _position.y + 1;
}

/* Exception */

char const * APiece::OutSidePositionException::what() const throw() {
    return "Position is outside";
}

/* Operator Overload */

std::ostream &   operator<<( std::ostream & o, APiece const & i ) {
    o << i.getXRepresentation() << i.getYRepresentation();
    return o;
}