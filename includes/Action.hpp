/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:31:31 by amineau           #+#    #+#             */
/*   Updated: 2021/01/27 19:25:44 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_HPP
#define ACTION_HPP

// #include "Piece.hpp"
#include "Player.hpp"
#include "Spot.hpp"

class GameStatus;
class Player;
class Piece;

class Action {
public:
	Action();
	Action(Action const&);
	Action(GameStatus*, Player*);
	virtual ~Action();

	virtual bool isLegal() const = 0;
	virtual void execute() = 0;

	virtual Player* getPlayer() const;

	Action& operator=(Action const&);

protected:
	GameStatus* _gameStatus;
	Player*		_player;
};

#endif