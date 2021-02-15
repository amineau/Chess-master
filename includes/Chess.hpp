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
#include "EnPassantMove.hpp"
#include "Exporter.hpp"
#include "GameStatus.hpp"
#include "Loader.hpp"
#include "Move.hpp"
#include "SimpleMove.hpp"

class Chess {

public:
	Chess();
	Chess(Chess const&);
	~Chess();

	Player*		getPlayerWhite() const;
	Player*		getPlayerBlack() const;
	GameStatus* getGameStatus() const;

	bool			  loadFen(const std::string& fen);
	const std::string exportFen() const;

	Move* getMoveAction(Player* player, const std::string& start, const std::string& end) const;
	void  makeAction(Action*);

	Chess& operator=(Chess const&);

private:
	Player*		_playerWhite;
	Player*		_playerBlack;
	GameStatus* _gameStatus;
};

#endif
