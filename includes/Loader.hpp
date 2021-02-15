/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:42:54 by amineau           #+#    #+#             */
/*   Updated: 2021/01/23 01:09:31 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_HPP
#define LOADER_HPP

#include "GameStatus.hpp"

class Loader {
public:
	Loader();
	Loader(Loader const&);
	Loader(GameStatus*);
	~Loader();

	bool fen(const std::string&);

	Loader& operator=(Loader const&);

private:
	bool _fenBoard(const std::string&);
	bool _fenCurrentPlayer(const std::string&);
	bool _fenCastlingsAvailable(const std::string&);
	bool _fenEnPassantTargetSpot(const std::string&);
	bool _fenHalfMoveClock(const std::string&);
	bool _fenFullMoveCounter(const std::string&);

	GameStatus* _gameStatus;
};

#endif