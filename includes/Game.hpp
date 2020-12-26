/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:46:32 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:44:46 by amineau          ###   ########.fr       */
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

	void start(Player p1, Player p2);
	void playerMoved(Player, size_t startX, size_t startY, size_t endX, size_t endY);
	void makeMove(Player player, Move move);

	Game& operator=(Game const&);

private:
	Board			   _board;
	Player*			   _currentTurn;
	Player			   _playerWhite;
	Player			   _playerBlack;
	std::vector<Move*> _movesPlayed;
};

#endif
