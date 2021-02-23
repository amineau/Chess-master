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
	GameStatus(Player* white, Player* black);
	GameStatus(GameStatus const&);
	~GameStatus();

	t_status		   getStatus() const;
	Board*			   getBoard() const;
	Player*			   getPlayerWhite() const;
	Player*			   getPlayerBlack() const;
	Spot*			   getBox(const std::string& pos) const;
	Piece*			   getPiece(const std::string& pos) const;
	Spot*			   getBox(size_t x, size_t y) const;
	Piece*			   getPiece(size_t x, size_t y) const;
	Player*			   getCurrentTurn() const;
	std::vector<Move*> getMovesPlayed() const;
	Spot*			   getEnPassantTargetSpot() const;
	short			   getHalfMoveClock() const;
	short			   getFullMoveCounter() const;
	bool			   getKingSideCastlingAvailable(bool isWhitePlayer) const;
	bool			   getQueenSideCastlingAvailable(bool isWhitePlayer) const;

	void setStatus(t_status);
	void setBoard(Board*);
	void setCurrentTurn(Player* player);
	void setEnPassantTargetSpot(Spot*);
	void setHalfMoveClock(int);
	void setFullMoveCounter(int);
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
	Board*			   _board;
	Player*			   _playerWhite;
	Player*			   _playerBlack;
	Player*			   _currentTurn;
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