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

// #include "Action.hpp"
#include "CastlingMove.hpp"
#include "EnPassantMove.hpp"
#include "Exporter.hpp"
#include "GameStatus.hpp"
#include "Loader.hpp"
#include "Move.hpp"
#include "SimpleMove.hpp"

enum e_result {
	WHITEWIN,
	BLACKWIN,
	DRAW
};
typedef enum e_result t_result;

class Chess {

public:
	Chess();
	Chess(Chess const&);
	~Chess();

	Player* getPlayerWhite() const { return const_cast<Player*>(&_playerWhite); }
	Player* getPlayerBlack() const { return const_cast<Player*>(&_playerBlack); }
	Player* getCurrentPlayer() const { return _gameStatus->getCurrentPlayer(); }
	Piece*	getPiece(const std::string& pos) const { return _gameStatus->getPiece(pos); }
	Piece*	getPiece(size_t x, size_t y) const { return _gameStatus->getPiece(x, y); }

	bool			  load(const std::string& fen);
	const std::string fen() const;

	std::vector<Spot*> validSpots(const std::string& pos) const;
	std::vector<Spot*> validSpots(size_t x, size_t y) const;
	std::vector<Move*> history() const { return _gameStatus->getMovesPlayed(); }

	Move* getMoveAction(Player* player, const std::string& start, const std::string& end) const;
	bool  makeAction(Action*);

	Chess& operator=(Chess const&);

private:
	Player		_playerWhite;
	Player		_playerBlack;
	GameStatus* _gameStatus;
};

#endif
