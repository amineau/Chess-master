/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastlingMove.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:50:51 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 21:17:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CastlingMove.hpp"
#include "King.hpp"

CastlingMove::CastlingMove()
	: Move()
{
	return;
}

CastlingMove::CastlingMove(GameStatus* gameStatus, Player* player, Spot* start, Spot* end)
	: Move(gameStatus, player, start, end)
{
	return;
}

CastlingMove::CastlingMove(CastlingMove const& src)
	: Move()
{
	*this = src;
	return;
}

CastlingMove::~CastlingMove()
{
	return;
}

CastlingMove& CastlingMove::operator=(CastlingMove const& rhs)
{
	if (this != &rhs) {
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_pieceMoved = rhs._pieceMoved;
		this->_pieceKilled = rhs._pieceKilled;
	}
	return *this;
}

bool CastlingMove::isLegal() const
{
	King* king = dynamic_cast<King*>(this->_pieceMoved);

	return king
		&& king->isWhite() == this->_player->isWhite()
		&& this->_player == this->_gameStatus->getCurrentTurn()
		&& (king->canKingSideCastlingMoves(this->_gameStatus, this->_start, this->_end)
			|| king->canQueenSideCastlingMoves(this->_gameStatus, this->_start, this->_end));
}

void CastlingMove::execute()
{
	if (this->_pieceKilled)
		this->_pieceKilled->killed();
	this->_end->setPiece(this->_pieceMoved);
	this->_start->setPiece(0);
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);

	this->_gameStatus->setEnPassantTargetSpot(0);
	if (this->_pieceMoved->getType() == PAWN || !this->_pieceKilled)
		this->_gameStatus->incrementHalfMoveClock();
}

const std::string CastlingMove::getRepr() const
{
	std::stringstream ss;

	ss << *this->_start << (this->_pieceKilled ? 'x' : '-') << *this->_end;
	return ss.str();
}