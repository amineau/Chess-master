/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:36:07 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:07:30 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Action.hpp"

Action::Action()
{
	return;
}

Action::Action(Action const& src)
{
	*this = src;
	return;
}

Action::Action(GameStatus* gameStatus, Player* player)
	: _gameStatus(gameStatus)
	, _player(player)
{
	return;
}

Action::~Action()
{
	return;
}

Player* Action::getPlayer() const
{
	return this->_player;
}

Action& Action::operator=(Action const& rhs)
{
	if (this != &rhs) {
		this->_player = rhs._player;
		this->_gameStatus = rhs._gameStatus;
	}
	return *this;
}
