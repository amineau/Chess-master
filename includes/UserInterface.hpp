/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:01:26 by amineau           #+#    #+#             */
/*   Updated: 2021/05/18 20:15:35 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "Chess.hpp"
#include "chessmaster.hpp"

#define NEWGAME 1
#define LOADGAME 2
#define QUIT 3

class UserInterface {
public:
	virtual ~UserInterface() {};
	short virtual displayMenu() const = 0;
	void virtual start(const std::string fen) = 0;
	// void virtual loadChess(Save save) = 0;
	// Save virtual saveChess() = 0;

protected:
	Chess* _chess;
};

#endif