/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 21:54:16 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player()
{
	return;
}

Player::Player(bool isWhite)
	: _isWhite(isWhite)
{
	std::cout << "Player CONSTRUCTOR " << this->_isWhite << std::endl;
	return;
}

Player::Player(Player const& src)
{
	*this = src;
	return;
}

Player::~Player()
{
	std::cout << "Player DECONSTRUCTOR " << this->_isWhite << std::endl;
	return;
}

bool Player::isWhite() const
{
	return this->_isWhite;
}

Player& Player::operator=(Player const& rhs)
{
	if (this != &rhs) {
		this->_isWhite = rhs._isWhite;
	}
	return *this;
}

bool Player::operator==(Player const& rhs)
{
	return this->_isWhite == rhs._isWhite;
}

std::ostream& operator<<(std::ostream& o, Player const& i)
{
	o << (i.isWhite() ? "White" : "Black");
	return o;
}