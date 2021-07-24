/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:46:41 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 21:57:14 by amineau          ###   ########.fr       */
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

void Loader::fen(const std::string& str)
{
	const std::vector<std::string> fenSplit = split(str, ' ');

	this->_gameStatus->clear();
	this->_gameStatus->setBoard(new Board());

	if (fenSplit.size() != 6)
		throw Loader::FenParsingException("Size of fen split is invalid.");
	this->_fenBoard(fenSplit[0]);
	this->_fenCurrentPlayer(fenSplit[1]);
	this->_fenCastlingsAvailable(fenSplit[2]);
	this->_fenEnPassantTargetSpot(fenSplit[3]);
	this->_fenHalfMoveClock(fenSplit[4]);
	this->_fenFullMoveCounter(fenSplit[5]);
}

Loader& Loader::operator=(Loader const& rhs)
{
	if (this != &rhs) {
		this->_gameStatus = rhs._gameStatus;
	}
	return *this;
}

void Loader::_fenBoard(const std::string& str)
{
	if (!this->_gameStatus->getBoard()->loadFen(str))
		throw Loader::FenParsingException("Parsing board has failed.");
}

void Loader::_fenCurrentPlayer(const std::string& str)
{
	if (!str.compare("w"))
		this->_gameStatus->setCurrentPlayer(this->_gameStatus->getPlayerWhite());
	else if (!str.compare("b"))
		this->_gameStatus->setCurrentPlayer(this->_gameStatus->getPlayerBlack());
	else
		throw Loader::FenParsingException("Current player must be 'w' or 'b'.");
}
void Loader::_fenCastlingsAvailable(const std::string& str)
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
	if (str[index] && str.compare("-"))
		throw Loader::FenParsingException("Parsing castling has failed.");
}
void Loader::_fenEnPassantTargetSpot(const std::string& str)
{
	try {
		this->_gameStatus->setEnPassantTargetSpot(this->_gameStatus->getSpot(str));
		if (!(this->_gameStatus->getEnPassantTargetSpot() && (str[1] == '3' || str[1] == '6')))
			throw Loader::FenParsingException("Parsing en passant has failed.");
	} catch (const Board::IndexOutOfBoardException&) {
		if (str.compare("-"))
			throw Loader::FenParsingException("Parsing en passant has failed.");
	}
}
void Loader::_fenHalfMoveClock(const std::string& str)
{
	if (!isNumber(str))
		throw Loader::FenParsingException("Half move clock must be an integer.");
	this->_gameStatus->setHalfMoveClock(stoi(str));
}
void Loader::_fenFullMoveCounter(const std::string& str)
{
	if (!isNumber(str))
		throw Loader::FenParsingException("Full move counter must be an integer.");
	this->_gameStatus->setFullMoveCounter(stoi(str));
}

/* Exception */

Loader::FenParsingException::FenParsingException()
	: runtime_error("Fen parsing has failed")
{
	return;
}
Loader::FenParsingException::FenParsingException(std::string msg)
	: runtime_error(msg.insert(0, "Fen parsing has failed with this error :\n\t"))
{
	return;
}