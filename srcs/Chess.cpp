/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chess.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2021/01/20 00:14:30 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Chess.hpp"
#include "Bishop.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

Chess::Chess()
	: _playerWhite(new Player(true))
	, _playerBlack(new Player(false))
{
	std::cout << "Chess CONSTRUCTOR" << std::endl;
	this->_gameStatus = new GameStatus(this->_playerWhite, this->_playerBlack);
	return;
}

Chess::Chess(Chess const& src)
{
	std::cout << "Chess CONSTRUCTOR BY REF" << std::endl;
	*this = src;
	return;
}

Chess::~Chess()
{
	std::cout << "Chess DECONSTRUCTOR" << std::endl;
	delete this->_playerWhite;
	delete this->_playerBlack;
	delete this->_gameStatus;
	return;
}

Chess& Chess::operator=(Chess const& rhs)
{
	if (this != &rhs) {
		this->_playerWhite = rhs._playerWhite;
		this->_playerBlack = rhs._playerBlack;
		this->_gameStatus = rhs._gameStatus;
	}
	return *this;
}

/* Accessors */

Player* Chess::getPlayerWhite() const
{
	return this->_playerWhite;
}

Player* Chess::getPlayerBlack() const
{
	return this->_playerBlack;
}

GameStatus* Chess::getGameStatus() const
{
	return this->_gameStatus;
}

/* Members functions */

Move* Chess::getMoveAction(Player* player, const std::string& start, const std::string& end) const
{
	Spot* startSpot = this->_gameStatus->getBox(start);
	Spot* endSpot = this->_gameStatus->getBox(end);

	if (startSpot->getPiece()
		&& startSpot->getPiece()->getType() == PAWN
		&& endSpot == this->_gameStatus->getEnPassantTargetSpot())
		return new EnPassantMove(this->_gameStatus, player, startSpot, endSpot);
	return new SimpleMove(this->_gameStatus, player, startSpot, endSpot);
}

void Chess::makeAction(Action* action)
{
	action->execute();
}

bool Chess::loadFen(const std::string& fen)
{
	Loader loader(this->_gameStatus);

	return loader.fen(fen);
}

const std::string Chess::exportFen() const
{
	Exporter exporter(this->_gameStatus);

	return exporter.fen();
}