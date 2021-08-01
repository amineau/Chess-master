/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:42:54 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:31:07 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_HPP
#define LOADER_HPP

#include "Game/GameStatus.hpp"

class Loader {
public:
	Loader();
	Loader(Loader const&);
	Loader(GameStatus*);
	~Loader();

	void fen(const std::string&);

	Loader& operator=(Loader const&);

	class FenParsingException : public std::runtime_error {
	public:
		FenParsingException();
		FenParsingException(std::string msg);
	};

private:
	void _fenBoard(const std::string&);
	void _fenCurrentPlayer(const std::string&);
	void _fenCastlingsAvailable(const std::string&);
	void _fenEnPassantTargetSpot(const std::string&);
	void _fenHalfMoveClock(const std::string&);
	void _fenFullMoveCounter(const std::string&);

	GameStatus* _gameStatus;
};

#endif