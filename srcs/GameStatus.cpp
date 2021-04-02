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
	: _board(Board())
{
	return;
}

GameStatus::GameStatus(Player white, Player black)
	: _board(Board())
	, _playerWhite(white)
	, _playerBlack(black)
{
	// std::cout << "GameStatus CONSTRUCTOR" << std::endl;
	return;
}

GameStatus::GameStatus(GameStatus const& src)
{
	// std::cout << "GameStatus CONSTRUCTOR BY REF" << std::endl;
	*this = src;
	return;
}

GameStatus::~GameStatus()
{
	// std::cout << "GameStatus DECONSTRUCTOR" << std::endl;
	for (Move* movePlayed : this->_movesPlayed)
		delete movePlayed;
	return;
}

GameStatus& GameStatus::operator=(GameStatus const& rhs)
{
	// std::cout << "GameStatus OPERATOR =" << std::endl;

	if (this != &rhs) {
		this->_status = rhs._status;
		this->_board = rhs._board;
		this->_playerWhite = rhs._playerWhite;
		this->_playerBlack = rhs._playerBlack;
		if (rhs._currentPlayer)
			this->_currentPlayer = rhs._currentPlayer->isWhite() ? &_playerWhite : &_playerBlack;
		else
			this->_currentPlayer = nullptr;
		this->_enPassantTargetSpot = rhs._enPassantTargetSpot ? this->_board.getSpot(rhs._enPassantTargetSpot->getRepr()) : nullptr;
		this->_halfMoveClock = rhs._halfMoveClock;
		this->_fullMoveCounter = rhs._fullMoveCounter;
		this->_kingSideCastlingWhiteAvailable = rhs._kingSideCastlingWhiteAvailable;
		this->_kingSideCastlingBlackAvailable = rhs._kingSideCastlingBlackAvailable;
		this->_queenSideCastlingWhiteAvailable = rhs._queenSideCastlingWhiteAvailable;
		this->_queenSideCastlingBlackAvailable = rhs._queenSideCastlingBlackAvailable;
		for (Move* rhsMovePlayed : rhs._movesPlayed) {
			this->_movesPlayed.push_back(rhsMovePlayed->clone());
		}
	}
	return *this;
}

/* Accessors */

/*** Getters ***/

Spot* GameStatus::getSpot(const std::string& pos) const
{
	return this->getBoard()->getSpot(pos);
}

Spot* GameStatus::getSpot(size_t x, size_t y) const
{
	return this->getBoard()->getSpot(x, y);
}

Piece* GameStatus::getPiece(const std::string& pos) const
{
	return this->getSpot(pos)->getPiece();
}

Piece* GameStatus::getPiece(size_t x, size_t y) const
{
	return this->getSpot(x, y)->getPiece();
}

bool GameStatus::getKingSideCastlingAvailable(bool isWhitePlayer) const
{
	if (isWhitePlayer)
		return this->_kingSideCastlingWhiteAvailable;
	return this->_kingSideCastlingBlackAvailable;
}

bool GameStatus::getQueenSideCastlingAvailable(bool isWhitePlayer) const
{
	if (isWhitePlayer)
		return this->_queenSideCastlingWhiteAvailable;
	return this->_queenSideCastlingBlackAvailable;
}

/*** Setters ***/

void GameStatus::setKingSideCastlingAvailable(bool kingSideCastlingAvailable, bool isWhitePlayer)
{
	if (isWhitePlayer)
		this->_kingSideCastlingWhiteAvailable = kingSideCastlingAvailable;
	else
		this->_kingSideCastlingBlackAvailable = kingSideCastlingAvailable;
}

void GameStatus::setQueenSideCastlingAvailable(bool queenSideCastlingAvailable, bool isWhitePlayer)
{
	if (isWhitePlayer)
		this->_queenSideCastlingWhiteAvailable = queenSideCastlingAvailable;
	else
		this->_queenSideCastlingBlackAvailable = queenSideCastlingAvailable;
}

/* Member functions */

void GameStatus::updateStatus()
{
	bool isWhite = this->_currentPlayer->isWhite();
	bool isCheck = this->isCheck(isWhite);

	if (this->hasNoMovePossible(isWhite)) {
		if (isCheck)
			this->_status = isWhite ? WHITECHECKMATED : BLACKCHECKMATED;
		else
			this->_status = STALEMATE;

	} else if (isCheck)
		this->_status = isWhite ? WHITECHECKED : BLACKCHECKED;
	else
		this->_status = INPROGRESS;
}

void GameStatus::pushTurn()
{
	if (*_currentPlayer == _playerBlack) {
		incrementFullMoveCounter();
		_currentPlayer = &_playerWhite;
	} else
		_currentPlayer = &_playerBlack;
}

void GameStatus::pushMove(Move* move)
{
	this->_movesPlayed.push_back(move);
}

void GameStatus::incrementHalfMoveClock()
{
	this->_halfMoveClock++;
	if (this->_halfMoveClock == 50)
		this->_status = STALEMATE; //TODO: verifier les conditions
}

void GameStatus::resetHalfMoveClock()
{
	this->_halfMoveClock = 0;
}

void GameStatus::incrementFullMoveCounter()
{
	this->_fullMoveCounter++; //TODO: idem
}

bool GameStatus::isCheck(bool isWhite) const
{
	return isAttacked(_board.getSpotKing(isWhite), isWhite);
}

bool GameStatus::hasNoMovePossible(bool isWhite) const
{
	Piece* piece;

	for (size_t x = 0; x < 8; x++) {
		for (size_t y = 0; y < 8; y++) {
			piece = this->getPiece(x, y);
			if (piece && piece->isWhite() == isWhite
				&& piece->validSpots(this, this->getSpot(x, y)).size())
				return false;
		}
	}
	return true;
}

bool GameStatus::isAttacked(Spot* spot, bool isWhite) const
{
	Piece*			   piece;
	std::vector<Spot*> validSpots;

	for (size_t x = 0; x < 8; x++) {
		for (size_t y = 0; y < 8; y++) {
			piece = this->getPiece(x, y);
			if (piece && piece->isWhite() != isWhite) {
				validSpots = piece->validSpotsWithoutCheck(this, this->getSpot(x, y));
				if (std::find(validSpots.begin(), validSpots.end(), spot) != validSpots.end())
					return true;
			}
		}
	}
	return false;
}

bool GameStatus::moveCausesCheck(const Spot* start, const Spot* end) const
{
	GameStatus clone = *this;
	Spot*	   startSpot = clone.getSpot(start->getX(), start->getY());
	Spot*	   endSpot = clone.getSpot(end->getX(), end->getY());
	Piece*	   piece = startSpot->getPiece();

	startSpot->setPiece(0);
	endSpot->setPiece(piece);
	return clone.isCheck(piece->isWhite());
}

bool GameStatus::moveCausesCheck(const std::vector<std::pair<Spot*, Spot*>> moves) const
{
	GameStatus clone = *this;
	Piece*	   piece;

	for (std::pair<Spot*, Spot*> move : moves) {
		move.first = clone.getSpot(move.first->getX(), move.first->getY());
		move.second = clone.getSpot(move.second->getX(), move.second->getY());
		piece = move.first->getPiece();
		move.first->setPiece(0);
		move.second->setPiece(piece);
	}
	return clone.isCheck(piece->isWhite());
}

void GameStatus::clear()
{
	this->_board = Board();
	this->_enPassantTargetSpot = 0;
	this->_currentPlayer = 0;
	this->_movesPlayed = std::vector<Move*>();
	this->_kingSideCastlingWhiteAvailable = false;
	this->_kingSideCastlingBlackAvailable = false;
	this->_queenSideCastlingWhiteAvailable = false;
	this->_queenSideCastlingBlackAvailable = false;
}
