/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exporter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:23:04 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:07:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exporter.hpp"

Exporter::Exporter()
{
	return;
}

Exporter::Exporter(Exporter const& src)
{
	*this = src;
	return;
}

Exporter::Exporter(GameStatus* gameStatus)
	: _gameStatus(gameStatus)
{
	return;
}

Exporter::~Exporter()
{
	return;
}

Exporter& Exporter::operator=(Exporter const& rhs)
{
	if (this != &rhs) {
		this->_gameStatus = rhs._gameStatus;
	}
	return *this;
}

const std::string Exporter::fen() const
{
	std::stringstream ss;

	ss << this->_fenBoard() << ' '
	   << this->_fenCurrentPlayer() << ' '
	   << this->_fenCastlingsAvailable() << ' '
	   << this->_fenEnPassantTargetSpot() << ' '
	   << this->_fenHalfMoveClock() << ' '
	   << this->_fenFullMoveCounter();
	return ss.str();
}

const std::string Exporter::_fenBoard() const
{
	return this->_gameStatus->getBoard()->exportFen();
}

const std::string Exporter::_fenCurrentPlayer() const
{
	return this->_gameStatus->getCurrentPlayer()->isWhite() ? "w" : "b";
}
const std::string Exporter::_fenCastlingsAvailable() const
{
	std::string str = "";

	if (this->_gameStatus->getKingSideCastlingAvailable(true))
		str += 'K';
	if (this->_gameStatus->getKingSideCastlingAvailable(false))
		str += 'Q';
	if (this->_gameStatus->getQueenSideCastlingAvailable(true))
		str += 'k';
	if (this->_gameStatus->getQueenSideCastlingAvailable(false))
		str += 'q';
	if (str.empty())
		str = "-";
	return str;
}
const std::string Exporter::_fenEnPassantTargetSpot() const
{
	Spot* targetSpot = this->_gameStatus->getEnPassantTargetSpot();
	return targetSpot ? targetSpot->getRepr() : "-";
}
const std::string Exporter::_fenHalfMoveClock() const
{
	return std::to_string(this->_gameStatus->getHalfMoveClock());
}
const std::string Exporter::_fenFullMoveCounter() const
{
	return std::to_string(this->_gameStatus->getFullMoveCounter());
}