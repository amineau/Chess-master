/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:46:32 by amineau           #+#    #+#             */
/*   Updated: 2021/01/05 18:36:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Move.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

class Game {

public:
	Game();
	Game(Game const&);
	~Game();

	Board			  getBoard() const;
	std::vector<Move> getMovesPlayed() const;
	Player			  getPlayerWhite() const;
	Player			  getPlayerBlack() const;

	void initialize();
	void start(Player p1, Player p2);
	bool playerMoved(Player* player, size_t startX, size_t startY, size_t endX, size_t endY);
	bool makeMove(Player* player, Move move);

	Game& operator=(Game const&);

private:
	Board			  _board;
	Player*			  _currentTurn;
	Player			  _playerWhite;
	Player			  _playerBlack;
	std::vector<Move> _movesPlayed;
};

#endif
