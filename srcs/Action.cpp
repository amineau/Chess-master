/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:36:07 by amineau           #+#    #+#             */
/*   Updated: 2021/05/14 23:56:00 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Action.hpp"
#include "GameStatus.hpp"

Action::Action()
{
	return;
}

Action::Action(Action const& src)
{
	*this = src;
	return;
}

Action::Action(GameStatus* gameStatus)
	: _gameStatus(gameStatus)
{
	_isWhitePlayer = _gameStatus->getCurrentPlayer()->isWhite();
	return;
}

Action::~Action()
{
	return;
}

Action& Action::operator=(Action const& rhs)
{
	if (this != &rhs) {
		this->_isWhitePlayer = rhs._isWhitePlayer;
		this->_gameStatus = rhs._gameStatus;
	}
	return *this;
}
