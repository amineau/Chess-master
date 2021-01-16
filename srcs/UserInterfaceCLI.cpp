/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceCLI.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:57 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 01:11:23 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterfaceCLI.hpp"

UserInterfaceCLI::UserInterfaceCLI()
{
	return;
}

UserInterfaceCLI::UserInterfaceCLI(UserInterfaceCLI const& src)
{
	*this = src;
	return;
}

UserInterfaceCLI::~UserInterfaceCLI()
{
	return;
}

UserInterfaceCLI& UserInterfaceCLI::operator=(UserInterfaceCLI const& rhs)
{
	if (this != &rhs)
		this->_game = rhs._game;
	return *this;
}

short UserInterfaceCLI::displayMenu() const
{
	char entry = 0;

	while (entry != '1' && entry != '2' && entry != '3') {
		if (entry != 0)
			std::cout << "Enter a valid choice" << std::endl;
		std::cout << "1/ Start new game" << std::endl
				  << "2/ Load game" << std::endl
				  << "3/ Quit" << std::endl
				  << "Enter the option number : ";
		std::cin >> entry;
	}

	return entry - '0';
}
void UserInterfaceCLI::start()
{
	std::string entry;
	std::string arg1;
	std::string arg2;
	std::string arg3;
	std::string arg4;

	Spot*  spot;
	Piece* piece;
	this->_game = Game();
	this->_game.load(settings::defaultFile);

	while (1) {
		std::cout << "Command : ";
		std::cin >> entry;
		if (!entry.compare("help")) {
			std::cout << std::endl
					  << "\thelp\tDisplay this command" << std::endl
					  << "\tdisplay\tDisplay game board" << std::endl
					  << "\tmove x y x y\tMove from x y start position to x y end position" << std::endl
					  << "\tvalid-moves x y\tValid moves to a piece at x y position" << std::endl
					  << "\tlist\tList of moves" << std::endl
					  << "\tturn\tCurrent player turn" << std::endl
					  << "\texit\tQuit program" << std::endl
					  << "\tquit\tQuit program" << std::endl
					  << std::endl;
		} else if (!entry.compare("turn")) {
			std::cout << *this->_game.getCurrentTurn() << std::endl;
		} else if (!entry.compare("display")) {
			std::cout << *this->_game.getBoard();
		} else if (!entry.compare("move")) {
			std::cin >> arg1 >> arg2 >> arg3 >> arg4;
			if (this->_game.playerMoved(
					this->_game.getCurrentTurn(),
					std::stoi(arg1),
					std::stoi(arg2),
					std::stoi(arg3),
					std::stoi(arg4)))
				std::cout << "Move ok" << std::endl;
			else
				std::cout << "Incorrect move" << std::endl;
		} else if (!entry.compare("valid-moves")) {
			std::cin >> arg1 >> arg2;
			spot = this->_game.getBoard()->getBox(std::stoi(arg1), std::stoi(arg2));
			piece = spot->getPiece();
			if (piece) {
				for (Spot* spot : piece->validSpots(this->_game.getBoard(), spot)) {
					std::cout << *spot << std::endl;
				}
			} else
				std::cout << "No piece in " << *spot << std::endl;
		} else if (!entry.compare("list")) {
			for (std::vector<Move>::iterator it = this->_game.getMovesPlayed().begin(); it != this->_game.getMovesPlayed().end(); ++it) {
				std::cout << *it;
				if (it->getPlayer()->isWhite())
					std::cout << ' ';
				else
					std::cout << std::endl;
			}
			std::cout << std::endl;
		} else if (!entry.compare("exit") || !entry.compare("quit")) {
			delete this->_game.getBoard();
			break;
		} else {
			std::cout << "Not a valid entry. Type help for command list" << std::endl;
		}
	}
}