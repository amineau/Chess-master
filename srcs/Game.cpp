/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2020/12/29 00:10:15 by amineau          ###   ########.fr       */
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

void Game::initialize()
{
	char entry = 0;

	while (entry != '1' && entry != '2') {
		if (entry != 0)
			std::cout << "Enter a valid choice" << std::endl;
		std::cout << "1/ Start a new game" << std::endl
				  << "2/ Quit" << std::endl
				  << "Enter the option number : ";
		std::cin >> entry;
	}

	if (entry == '1') {
		this->start(Player(true), Player(false));
	}
}

void Game::start(Player p1, Player p2)
{
	std::string entry;

	this->_playerWhite = p1;
	this->_playerBlack = p2;
	this->_board = Board();
	this->_currentTurn = &this->_playerWhite;
	std::cout << this->_board;
	while (1) {
		std::cout << "Command : ";
		std::cin >> entry;
		if (!entry.compare("help")) {
			std::cout << std::endl
					  << "\thelp\tDisplay this command" << std::endl
					  << "\tdisplay\tDisplay game board" << std::endl
					  << "\tturn\tCurrent player turn" << std::endl
					  << "\texit\tQuit program" << std::endl
					  << "\tquit\tQuit program" << std::endl
					  << std::endl;
		} else if (!entry.compare("turn")) {
			std::cout << *this->_currentTurn << std::endl;
		} else if (!entry.compare("display")) {
			std::cout << this->_board;
		} else if (!entry.compare("exit") || !entry.compare("quit")) {
			break;
		} else {
			std::cout << "Not a valid entry. Type help for command list" << std::endl;
		}
	}
}