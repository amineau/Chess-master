/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chess.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:46:32 by amineau           #+#    #+#             */
/*   Updated: 2021/01/20 00:13:08 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Move.hpp"
#include "Player.hpp"
#include "utils.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

class Chess {

public:
	Chess();
	Chess(Chess const&);
	~Chess();

	Board*			  getBoard() const;
	Spot*			  getBox(const std::string& pos) const;
	Piece*			  getPiece(const std::string& pos) const;
	Player*			  getCurrentTurn() const;
	std::vector<Move> getMovesPlayed() const;
	Player*			  getPlayerWhite() const;
	Player*			  getPlayerBlack() const;
	Spot*			  getEnPassantTargetSpot() const;
	short			  getHalfMoveClock() const;
	short			  getFullMoveCounter() const;
	bool			  getCastlingKingWhiteAvailable() const;
	bool			  getCastlingKingBlackAvailable() const;
	bool			  getCastlingQueenWhiteAvailable() const;
	bool			  getCastlingQueenBlackAvailable() const;

	void setCurrentTurn(Player* player);
	void setEnPassantTargetSpot(Spot*);
	void setCastlingKingWhiteAvailable(bool);
	void setCastlingKingBlackAvailable(bool);
	void setCastlingQueenWhiteAvailable(bool);
	void setCastlingQueenBlackAvailable(bool);

	bool			  load_fen(const std::string& fen);
	const std::string fen() const;

	bool playerMoved(Player* player, const std::string& start, const std::string& end);
	bool makeMove(Player* player, Move move);

	Chess& operator=(Chess const&);

private:
	bool _loadFenBoard(const std::string&);
	bool _loadFenCurrentPlayer(const std::string&);
	bool _loadFenCastlingsAvailable(const std::string&);
	bool _loadFenEnPassantTargetSpot(const std::string&);
	bool _loadFenHalfMoveClock(const std::string&);
	bool _loadFenFullMoveCounter(const std::string&);

	const std::string _fenBoard() const;
	const std::string _fenCurrentPlayer() const;
	const std::string _fenCastlingsAvailable() const;
	const std::string _fenEnPassantTargetSpot() const;
	const std::string _fenHalfMoveClock() const;
	const std::string _fenFullMoveCounter() const;

	Board*			  _board;
	Player*			  _currentTurn;
	Player*			  _playerWhite;
	Player*			  _playerBlack;
	std::vector<Move> _movesPlayed;
	Spot*			  _enPassantTargetSpot;
	short			  _halfMoveClock;
	short			  _fullMoveCounter;
	bool			  _castlingKingWhiteAvailable;
	bool			  _castlingKingBlackAvailable;
	bool			  _castlingQueenWhiteAvailable;
	bool			  _castlingQueenBlackAvailable;
};

#endif
