/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:49:19 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
{
	return;
}

Game::Game(Game const& src)
{
	*this = src;
	return;
}

Game::~Game()
{
	return;
}

Game& Game::operator=(Game const& rhs)
{
	if (this != &rhs) {
		this->_board = rhs._board;
		this->_currentTurn = rhs._currentTurn;
		this->_playerWhite = rhs._playerWhite;
		this->_playerBlack = rhs._playerBlack;
		this->_movesPlayed = rhs._movesPlayed;
	}
	return *this;
}

/* Accessors */

/* Members functions */

void Game::start(Player p1, Player p2)
{
	this->_playerWhite = p1;
	this->_playerBlack = p2;
	this->_board = Board();
	this->_currentTurn = &this->_playerWhite;
	while (1) {
	}
}