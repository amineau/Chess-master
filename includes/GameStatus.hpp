/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameStatus.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:28:51 by amineau           #+#    #+#             */
/*   Updated: 2021/05/23 15:54:03 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP

#include "Board.hpp"
#include "Player.hpp"
#include <vector>

class Move;
class Player;
class Board;
class Spot;
class Piece;

class GameStatus {
public:
	GameStatus();
	GameStatus(Player white, Player black);
	GameStatus(GameStatus const&);
	~GameStatus();

	Board*			   getBoard() const { return const_cast<Board*>(&_board); }
	Player*			   getPlayerWhite() const { return const_cast<Player*>(&_playerWhite); }
	Player*			   getPlayerBlack() const { return const_cast<Player*>(&_playerBlack); }
	Player*			   getCurrentPlayer() const { return _currentPlayer; }
	std::vector<Move*> getMovesPlayed() const { return _movesPlayed; }
	Spot*			   getEnPassantTargetSpot() const { return _enPassantTargetSpot; }
	short			   getHalfMoveClock() const { return _halfMoveClock; }
	short			   getFullMoveCounter() const { return _fullMoveCounter; }
	bool			   getKingSideCastlingAvailable(bool isWhitePlayer) const;
	bool			   getQueenSideCastlingAvailable(bool isWhitePlayer) const;
	Spot*			   getSpot(const std::string& pos) const;
	Piece*			   getPiece(const std::string& pos) const;
	Spot*			   getSpot(size_t x, size_t y) const;
	Piece*			   getPiece(size_t x, size_t y) const;

	void setBoard(Board* board) { _board = *board; }
	void setCurrentPlayer(Player* player) { _currentPlayer = player; }
	void setEnPassantTargetSpot(Spot* spot) { _enPassantTargetSpot = spot; }
	void setHalfMoveClock(int c) { _halfMoveClock = c; }
	void setFullMoveCounter(int c) { _fullMoveCounter = c; }
	void setKingSideCastlingAvailable(bool kingSideCastlingAvailable, bool isWhitePlayer);
	void setQueenSideCastlingAvailable(bool queenSideCastlingAvailable, bool isWhitePlayer);

	void pushTurn();
	void pushMove(Move*);
	void incrementHalfMoveClock();
	void resetHalfMoveClock();
	void incrementFullMoveCounter();

	bool isCheck(bool isWhite) const;
	bool hasNoMovePossible(bool isWhite) const;
	bool isAttacked(Spot* spot) const;
	bool moveCausesCheck(const Spot* start, const Spot* end) const;
	bool moveCausesCheck(const std::vector<std::pair<Spot*, Spot*>> moves) const;

	void clear();

	GameStatus& operator=(GameStatus const&);

private:
	Board			   _board;
	Player			   _playerWhite;
	Player			   _playerBlack;
	Player*			   _currentPlayer;
	std::vector<Move*> _movesPlayed;
	Spot*			   _enPassantTargetSpot;
	short			   _halfMoveClock;
	short			   _fullMoveCounter;
	bool			   _kingSideCastlingWhiteAvailable;
	bool			   _kingSideCastlingBlackAvailable;
	bool			   _queenSideCastlingWhiteAvailable;
	bool			   _queenSideCastlingBlackAvailable;
};

#endif