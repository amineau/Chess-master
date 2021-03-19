/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameStatus.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:28:51 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP

#include "Board.hpp"
#include "Move.hpp"
#include "Player.hpp"
#include "Spot.hpp"
#include "utils.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

class Move;

enum e_status {
	INPROGRESS,
	WHITECHECKED,
	BLACKCHECKED,
	WHITECHECKMATED,
	BLACKCHECKMATED,
	DRAW
};
typedef enum e_status t_status;

class GameStatus {
public:
	GameStatus();
	GameStatus(Player white, Player black);
	GameStatus(GameStatus const&);
	~GameStatus();

	t_status		   getStatus() const { return _status; }
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

	void setStatus(t_status status) { _status = status; }
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
	void incrementFullMoveCounter();

	bool isAttacked(Spot* spot, bool isWhite) const;

	void clear();

	GameStatus& operator=(GameStatus const&);

private:
	t_status		   _status;
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