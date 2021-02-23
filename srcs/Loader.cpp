/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:46:41 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:07:48 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loader.hpp"

Loader::Loader()
{
	return;
}

Loader::Loader(Loader const& src)
{
	*this = src;
	return;
}

Loader::Loader(GameStatus* gameStatus)
	: _gameStatus(gameStatus)
{
	return;
}

Loader::~Loader()
{
	return;
}

bool Loader::fen(const std::string& str)
{
	const std::vector<std::string> fenSplit = split(str, ' ');

	this->_gameStatus->clear();
	this->_gameStatus->setBoard(new Board());

	return (fenSplit.size() == 6
		&& this->_fenBoard(fenSplit[0])
		&& this->_fenCurrentPlayer(fenSplit[1])
		&& this->_fenCastlingsAvailable(fenSplit[2])
		&& this->_fenEnPassantTargetSpot(fenSplit[3])
		&& this->_fenHalfMoveClock(fenSplit[4])
		&& this->_fenFullMoveCounter(fenSplit[5]));
}

Loader& Loader::operator=(Loader const& rhs)
{
	if (this != &rhs) {
		this->_gameStatus = rhs._gameStatus;
	}
	return *this;
}

bool Loader::_fenBoard(const std::string& str)
{
	return this->_gameStatus->getBoard()->loadFen(str);
}

bool Loader::_fenCurrentPlayer(const std::string& str)
{
	if (!str.compare("w"))
		this->_gameStatus->setCurrentTurn(this->_gameStatus->getPlayerWhite());
	else if (!str.compare("b"))
		this->_gameStatus->setCurrentTurn(this->_gameStatus->getPlayerBlack());
	else
		return false;
	return true;
}
bool Loader::_fenCastlingsAvailable(const std::string& str)
{
	short index = 0;

	if (str[index] && str[index] == 'K') {
		this->_gameStatus->setKingSideCastlingAvailable(true, true);
		index++;
	}
	if (str[index] && str[index] == 'Q') {
		this->_gameStatus->setQueenSideCastlingAvailable(true, true);
		index++;
	}
	if (str[index] && str[index] == 'k') {
		this->_gameStatus->setKingSideCastlingAvailable(true, false);
		index++;
	}
	if (str[index] && str[index] == 'q') {
		this->_gameStatus->setQueenSideCastlingAvailable(true, false);
		index++;
	}
	return (!str[index] || !str.compare("-"));
}
bool Loader::_fenEnPassantTargetSpot(const std::string& str)
{
	try {
		this->_gameStatus->setEnPassantTargetSpot(this->_gameStatus->getBox(str));
		return this->_gameStatus->getEnPassantTargetSpot() && (str[1] == '3' || str[1] == '6');
	} catch (const Board::IndexOutOfBoardException&) {
		return !str.compare("-");
	}
}
bool Loader::_fenHalfMoveClock(const std::string& str)
{
	if (!isNumber(str))
		return false;
	this->_gameStatus->setHalfMoveClock(stoi(str));
	return true;
}
bool Loader::_fenFullMoveCounter(const std::string& str)
{
	if (!isNumber(str))
		return false;
	this->_gameStatus->setFullMoveCounter(stoi(str));
	return true;
}