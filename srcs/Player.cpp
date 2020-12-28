/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2020/12/28 19:44:57 by amineau          ###   ########.fr       */
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
	return;
}

Player::Player(Player const& src)
{
	*this = src;
	return;
}

Player::~Player()
{
	return;
}

Player& Player::operator=(Player const& rhs)
{
	if (this != &rhs) {
		this->_isWhite = rhs._isWhite;
	}
	return *this;
}

bool Player::isWhite() const
{
	return this->_isWhite;
}

std::ostream& operator<<(std::ostream& o, Player const& i)
{
	o << (i.isWhite() ? "White" : "Black");
	return o;
}