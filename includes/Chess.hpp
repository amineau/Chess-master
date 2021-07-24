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

#include "CastlingMove.hpp"
#include "EnPassantMove.hpp"
#include "Exporter.hpp"
#include "GameStatus.hpp"
#include "Loader.hpp"
#include "Move.hpp"
#include "SimpleMove.hpp"

enum e_status {
	INPROGRESS,
	CHECKMATE,			 // Echec et mat
	STALEMATE,			 // Impasse (50 coups)
	DRAW,				 // Pat
	TREEFOLDREPETITION,	 // Triple répétition
	INSUFFICIENTMATERIAL // Roi contre Roi seul ou Roi et fou ou cavalier
};
typedef enum e_status t_status;

class Chess {

public:
	Chess();
	Chess(Chess const&);
	~Chess();

	t_status		   getStatus() const { return _status; }
	Player*			   getPlayerWhite() const { return const_cast<Player*>(&_playerWhite); }
	Player*			   getPlayerBlack() const { return const_cast<Player*>(&_playerBlack); }
	Player*			   getCurrentPlayer() const { return _gameStatus->getCurrentPlayer(); }
	Piece*			   getPiece(const std::string& pos) const { return _gameStatus->getPiece(pos); }
	Piece*			   getPiece(size_t x, size_t y) const { return _gameStatus->getPiece(x, y); }
	Spot*			   getSpot(const std::string& pos) const { return _gameStatus->getSpot(pos); }
	Spot*			   getSpot(size_t x, size_t y) const { return _gameStatus->getSpot(x, y); }
	std::vector<Spot*> getWhiteSpots() const { return _gameStatus->getBoard()->getWhiteSpots(); }
	std::vector<Spot*> getBlackSpots() const { return _gameStatus->getBoard()->getBlackSpots(); }
	short			   getMoveCounter() const { return _gameStatus->getFullMoveCounter(); }

	void updateStatus();

	void			  load(const std::string& fen);
	const std::string fen() const;

	std::vector<Spot*> validSpots(const std::string& pos) const;
	std::vector<Spot*> validSpots(size_t x, size_t y) const;
	std::vector<Spot*> validSpots(const Spot* spot) const;
	std::vector<Move*> history() const { return _gameStatus->getMovesPlayed(); }

	Move* getMoveAction(const std::string& start, const std::string& end) const;
	Move* getMoveAction(Spot* start, Spot* end) const;
	bool  makeAction(Action*);

	Chess& operator=(Chess const&);

private:
	t_status	_status;
	Player		_playerWhite;
	Player		_playerBlack;
	GameStatus* _gameStatus;
};

#endif
