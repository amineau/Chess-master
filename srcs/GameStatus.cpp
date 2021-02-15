/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameStatus.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:49:19 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:07:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameStatus.hpp"

GameStatus::GameStatus()
	: _board(0)
{
	return;
}

GameStatus::GameStatus(Player* white, Player* black)
	: _board(0)
	, _playerWhite(white)
	, _playerBlack(black)
{
	return;
}

GameStatus::GameStatus(GameStatus const& src)
{
	*this = src;
	return;
}

GameStatus::~GameStatus()
{
	delete this->_board;
	for (Move* movePlayed : this->_movesPlayed)
		delete movePlayed;
	return;
}

GameStatus& GameStatus::operator=(GameStatus const& rhs)
{
	if (this != &rhs) {
		this->_status = rhs._status;
		this->_board = rhs._board;
		this->_playerWhite = rhs._playerWhite;
		this->_playerBlack = rhs._playerBlack;
		this->_currentTurn = rhs._currentTurn;
		this->_movesPlayed = rhs._movesPlayed;
		this->_enPassantTargetSpot = rhs._enPassantTargetSpot;
		this->_halfMoveClock = rhs._halfMoveClock;
		this->_fullMoveCounter = rhs._fullMoveCounter;
		this->_kingSideCastlingWhiteAvailable = rhs._kingSideCastlingWhiteAvailable;
		this->_kingSideCastlingBlackAvailable = rhs._kingSideCastlingBlackAvailable;
		this->_queenSideCastlingWhiteAvailable = rhs._queenSideCastlingWhiteAvailable;
		this->_queenSideCastlingBlackAvailable = rhs._queenSideCastlingBlackAvailable;
	}
	return *this;
}

/* Accessors */

/*** Getters ***/

t_status GameStatus::getStatus() const
{
	return this->_status;
}

Board* GameStatus::getBoard() const
{
	// if (!this->_board)
	// throw exception;
	return this->_board;
}

Player* GameStatus::getPlayerWhite() const
{
	return this->_playerWhite;
}

Player* GameStatus::getPlayerBlack() const
{
	return this->_playerBlack;
}

Spot* GameStatus::getBox(const std::string& pos) const
{
	return this->getBoard()->getBox(pos);
}

Spot* GameStatus::getBox(size_t x, size_t y) const
{
	return this->getBoard()->getBox(x, y);
}

Piece* GameStatus::getPiece(const std::string& pos) const
{
	return this->getBox(pos)->getPiece();
}

Piece* GameStatus::getPiece(size_t x, size_t y) const
{
	return this->getBox(x, y)->getPiece();
}

Player* GameStatus::getCurrentTurn() const
{
	return this->_currentTurn;
}

std::vector<Move*> GameStatus::getMovesPlayed() const
{
	return this->_movesPlayed;
}

Spot* GameStatus::getEnPassantTargetSpot() const
{
	return this->_enPassantTargetSpot;
}
short GameStatus::getHalfMoveClock() const
{
	return this->_halfMoveClock;
}
short GameStatus::getFullMoveCounter() const
{
	return this->_fullMoveCounter;
}
bool GameStatus::getKingSideCastlingWhiteAvailable() const
{
	return this->_kingSideCastlingWhiteAvailable;
}
bool GameStatus::getKingSideCastlingBlackAvailable() const
{
	return this->_kingSideCastlingBlackAvailable;
}
bool GameStatus::getQueenSideCastlingWhiteAvailable() const
{
	return this->_queenSideCastlingWhiteAvailable;
}
bool GameStatus::getQueenSideCastlingBlackAvailable() const
{
	return this->_queenSideCastlingBlackAvailable;
}

/*** Setters ***/

void GameStatus::setStatus(t_status status)
{
	this->_status = status;
}

void GameStatus::setBoard(Board* board)
{
	this->_board = board;
}

void GameStatus::setCurrentTurn(Player* player)
{
	this->_currentTurn = player;
}

void GameStatus::setEnPassantTargetSpot(Spot* enPassantTargetSpot)
{
	this->_enPassantTargetSpot = enPassantTargetSpot;
}
void GameStatus::setHalfMoveClock(int halfMoveClock)
{
	this->_halfMoveClock = halfMoveClock;
}
void GameStatus::setFullMoveCounter(int fullMoveCounter)
{
	this->_fullMoveCounter = fullMoveCounter;
}
void GameStatus::setKingSideCastlingWhiteAvailable(bool kingSideCastlingWhiteAvailable)
{
	this->_kingSideCastlingWhiteAvailable = kingSideCastlingWhiteAvailable;
}
void GameStatus::setKingSideCastlingBlackAvailable(bool kingSideCastlingBlackAvailable)
{
	this->_kingSideCastlingBlackAvailable = kingSideCastlingBlackAvailable;
}
void GameStatus::setQueenSideCastlingWhiteAvailable(bool queenSideCastlingWhiteAvailable)
{
	this->_queenSideCastlingWhiteAvailable = queenSideCastlingWhiteAvailable;
}
void GameStatus::setQueenSideCastlingBlackAvailable(bool queenSideCastlingBlackAvailable)
{
	this->_queenSideCastlingBlackAvailable = queenSideCastlingBlackAvailable;
}

/* Member functions */

void GameStatus::pushTurn()
{
	if (this->_currentTurn == this->_playerBlack) {
		this->incrementFullMoveCounter();
		this->_currentTurn = this->_playerWhite;
	} else
		this->_currentTurn = this->_playerBlack;
}

void GameStatus::pushMove(Move* move)
{
	this->_movesPlayed.push_back(move);
}

void GameStatus::incrementHalfMoveClock()
{
	this->_halfMoveClock++;
	if (this->_halfMoveClock == 50)
		this->_status = DRAW; //TODO: verifier les conditions
}
void GameStatus::incrementFullMoveCounter()
{
	this->_fullMoveCounter++; //TODO: idem
}

void GameStatus::clear()
{
	delete this->_board;
	this->_enPassantTargetSpot = 0;
	this->_currentTurn = 0;
	this->_movesPlayed = std::vector<Move*>();
	this->_kingSideCastlingWhiteAvailable = false;
	this->_kingSideCastlingBlackAvailable = false;
	this->_queenSideCastlingWhiteAvailable = false;
	this->_queenSideCastlingBlackAvailable = false;
}