/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceCLI.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:57 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:17 by amineau          ###   ########.fr       */
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
		this->_chess = rhs._chess;
	return *this;
}

short UserInterfaceCLI::displayMenu() const
{
	char entry = 0;

	while (entry != '1' && entry != '2' && entry != '3') {
		if (entry != 0)
			std::cout << "Enter a valid choice" << std::endl;
		std::cout << "1/ Start new chess" << std::endl
				  << "2/ Load chess" << std::endl
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

	Spot*		spot;
	Piece*		piece;
	GameStatus* gameStatus;
	Move*		move;
	this->_chess = new Chess();

	if (!this->_chess->loadFen(settings::defaultFenStart)) {
		std::cout << "Wrong parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	gameStatus = this->_chess->getGameStatus();

	while (1) {
		std::cout << "Command : ";
		std::cin >> entry;
		if (!entry.compare("help")) {
			std::cout << std::endl
					  << "\thelp\tDisplay this command" << std::endl
					  << "\tdisplay\tDisplay chess board" << std::endl
					  << "\tmove start end\tMove from start position to end position" << std::endl
					  << "\tvalid-moves start\tValid moves to a piece at start position" << std::endl
					  << "\tlist\tList of moves" << std::endl
					  << "\tturn\tCurrent player turn" << std::endl
					  << "\tfen\tDisplay the fen notation" << std::endl
					  << "\texit\tQuit program" << std::endl
					  << "\tquit\tQuit program" << std::endl
					  << std::endl;
		} else if (!entry.compare("turn")) {
			std::cout << *gameStatus->getCurrentPlayer() << std::endl;
		} else if (!entry.compare("display")) {
			this->displayBoard();
		} else if (!entry.compare("fen")) {
			std::cout << this->_chess->exportFen() << std::endl;
		} else if (!entry.compare("move")) {
			std::cin >> arg1 >> arg2;
			move = this->_chess->getMoveAction(
				gameStatus->getCurrentPlayer(), arg1, arg2);
			if (move->isLegal()) {
				this->_chess->makeAction(move);
				std::cout << "Move ok" << std::endl;

			} else {
				delete move;
				std::cout << "Incorrect move" << std::endl;
			}
		} else if (!entry.compare("valid-moves")) {
			std::cin >> arg1;
			spot = gameStatus->getSpot(arg1);
			piece = gameStatus->getPiece(arg1);
			if (piece) {
				if (piece->isWhite() == gameStatus->getCurrentPlayer()->isWhite())
					for (Spot* validSpot : piece->validSpots(gameStatus, spot))
						std::cout << *validSpot << std::endl;
			} else
				std::cout << "No piece in " << *spot << std::endl;
		} else if (!entry.compare("list")) {
			for (Move* movePlayed : gameStatus->getMovesPlayed()) {
				std::cout << *movePlayed;
				if (movePlayed->getPieceMoved()->isWhite())
					std::cout << ' ';
				else
					std::cout << std::endl;
			}
			std::cout << std::endl;
		} else if (!entry.compare("exit") || !entry.compare("quit")) {
			delete this->_chess;
			break;
		} else {
			std::cout << "Not a valid entry. Type help for command list" << std::endl;
		}
	}
}

void UserInterfaceCLI::displayBoard() const
{
	Piece* piece;

	std::cout << "\033[38;5;232;48;5;215m                    \033[0m" << std::endl;
	for (int y = 7; y >= 0; --y) {
		std::cout << "\033[38;5;232;48;5;215m" << y + 1 << " ";
		for (int x = 0; x <= 7; ++x) {
			if ((y + x) % 2)
				std::cout << "\033[48;5;255m";
			else
				std::cout << "\033[48;5;75m";
			piece = this->_chess->getGameStatus()->getPiece(x, y);
			if (piece != NULL) {
				if (piece->isWhite())
					std::cout << "\033[1;38;5;22m";
				else
					std::cout << "\033[1;38;5;232m";
				std::cout << *piece << " ";
			} else
				std::cout << "  ";
		}
		std::cout << "\033[38;5;232;48;5;215m  \033[0m" << std::endl;
	}
	std::cout << "\033[38;5;232;48;5;215m  a b c d e f g h   \033[0m" << std::endl;
}