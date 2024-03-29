/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:01:26 by amineau           #+#    #+#             */
/*   Updated: 2022/04/16 00:08:06 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "Game/Chess.hpp"
#include "config.hpp"

#define NEWGAME 1
#define LOADGAME 2
#define QUIT 3

class UserInterface {
public:
	virtual ~UserInterface() {};
	short virtual displayMenu() const = 0;
	short virtual chooseBackup(std::vector<std::tuple<int, std::string, const char *>>) const = 0;
	void virtual start(const std::string fen) = 0;
	// bool virtual backupRequire() const = 0;
	// std::string virtual getBackupName() const = 0;
	// std::string virtual getFen() const = 0;
	// void virtual loadChess(Save save) = 0;
	// Save virtual saveChess() = 0;

protected:
	Chess* _chess;
};

#endif