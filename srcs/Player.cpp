#include "Player.hpp"

Player::Player() {
	return;
}

Player::Player( bool isWhite )
    : _isWhite(isWhite)
{
	return;
}

Player::Player( Player const & src ) {
	*this = src;
	return;
}

Player::~Player() {
	return;
}

Player &	Player::operator=( Player const & rhs ) {
	if (this != &rhs) {
		this->_isWhite = rhs._isWhite;
	}
	return *this;
}

bool Player::isWhite() const {
    return this->_isWhite;
}