/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:01:26 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 01:15:07 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "Game.hpp"
#include "chessmaster.hpp"

#define NEWGAME 1
#define LOADGAME 2
#define QUIT 3

class UserInterface {
public:
	virtual ~UserInterface() {};
	short virtual displayMenu() const = 0;
	void virtual start() = 0;
	// void virtual loadGame(Save save) = 0;
	// Save virtual saveGame() = 0;

protected:
	Game _game;
};

#endif