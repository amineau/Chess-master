/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2021/01/05 18:10:32 by amineau          ###   ########.fr       */
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

Board Game::getBoard() const
{
	return this->_board;
}

std::vector<Move> Game::getMovesPlayed() const
{
	return this->_movesPlayed;
}

Player Game::getPlayerWhite() const
{
	return this->_playerWhite;
}
Player Game::getPlayerBlack() const
{
	return this->_playerBlack;
}

/* Members functions */

bool Game::playerMoved(Player* player, size_t startX, size_t startY, size_t endX, size_t endY)
{
	Move move = Move(player, this->_board.getBox(startX, startY), this->_board.getBox(endX, endY));
	return this->makeMove(player, move);
}

bool Game::makeMove(Player* player, Move move)
{
	Piece* piece = move.getPieceMoved();
	Piece* pieceKilled = move.getPieceKilled();
	std::cout << piece << std::endl;
	if (!piece || piece->isWhite() != player->isWhite() || player != this->_currentTurn)
		return false;
	if (!piece->canMoves(&this->_board, move.getStartSpot(), move.getEndSpot()))
		return false;
	if (pieceKilled)
		pieceKilled->killed();
	move.getEndSpot()->setPiece(piece);
	move.getStartSpot()->setPiece(NULL);
	this->_currentTurn = this->_currentTurn->isWhite() ? &this->_playerBlack : &this->_playerWhite;
	this->_movesPlayed.push_back(move);
	return true;
}

void Game::initialize()
{
	// char entry = 0;

	// while (entry != '1' && entry != '2') {
	// 	if (entry != 0)
	// 		std::cout << "Enter a valid choice" << std::endl;
	// 	std::cout << "1/ Start a new game" << std::endl
	// 			  << "2/ Quit" << std::endl
	// 			  << "Enter the option number : ";
	// 	std::cin >> entry;
	// }

	// if (entry == '1') {
	this->start(Player(true), Player(false));
	// }
}

void Game::start(Player p1, Player p2)
{
	std::string entry;
	std::string arg1;
	std::string arg2;
	std::string arg3;
	std::string arg4;

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
					  << "\tmove x y x y\tMove from x y start position to x y end position" << std::endl
					  << "\tlist\tList of moves" << std::endl
					  << "\tturn\tCurrent player turn" << std::endl
					  << "\texit\tQuit program" << std::endl
					  << "\tquit\tQuit program" << std::endl
					  << std::endl;
		} else if (!entry.compare("turn")) {
			std::cout << *this->_currentTurn << std::endl;
		} else if (!entry.compare("display")) {
			std::cout << this->_board;
		} else if (!entry.compare("move")) {
			std::cin >> arg1 >> arg2 >> arg3 >> arg4;
			if (this->playerMoved(
					this->_currentTurn,
					std::stoi(arg1),
					std::stoi(arg2),
					std::stoi(arg3),
					std::stoi(arg4)))
				std::cout << "Move ok" << std::endl;
			else
				std::cout << "Incorrect move" << std::endl;
		} else if (!entry.compare("list")) {
			for (std::vector<Move>::iterator it = this->_movesPlayed.begin(); it != this->_movesPlayed.end(); ++it) {
				std::cout << *it;
				if (it->getPlayer()->isWhite())
					std::cout << ' ';
				else
					std::cout << std::endl;
			}
			std::cout << std::endl;
		} else if (!entry.compare("exit") || !entry.compare("quit")) {
			break;
		} else {
			std::cout << "Not a valid entry. Type help for command list" << std::endl;
		}
	}
}