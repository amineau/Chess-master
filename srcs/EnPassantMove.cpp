/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnPassantMove.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:47:12 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:07:08 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnPassantMove.hpp"
#include "Pawn.hpp"

EnPassantMove::EnPassantMove()
	: Move()
{
	return;
}

EnPassantMove::EnPassantMove(GameStatus* gameStatus, Player* player, Spot* start, Spot* end)
	: Move(gameStatus, player, start, end)
{
	if (player->isWhite())
		this->_pieceKilled = gameStatus->getPiece(this->_end->getX(), 4);
	else
		this->_pieceKilled = gameStatus->getPiece(this->_end->getX(), 3);
	return;
}

EnPassantMove::EnPassantMove(EnPassantMove const& src)
	: Move()
{
	*this = src;
	return;
}

EnPassantMove::~EnPassantMove()
{
	return;
}

EnPassantMove& EnPassantMove::operator=(EnPassantMove const& rhs)
{
	if (this != &rhs) {
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_pieceMoved = rhs._pieceMoved;
		this->_pieceKilled = rhs._pieceKilled;
	}
	return *this;
}

bool EnPassantMove::isLegal() const
{
	Pawn* pawn = dynamic_cast<Pawn*>(this->_pieceMoved);

	return pawn
		&& pawn->getType() == PAWN
		&& pawn->isWhite() == this->_player->isWhite()
		&& this->_player == this->_gameStatus->getCurrentTurn()
		&& this->_end == this->_gameStatus->getEnPassantTargetSpot()
		&& pawn->canMovesEnPassant(this->_gameStatus, this->_start, this->_end);
}

void EnPassantMove::execute()
{
	if (this->_player->isWhite())
		this->_gameStatus->getBox(this->_end->getX(), 4)->setPiece(0);
	else
		this->_gameStatus->getBox(this->_end->getX(), 3)->setPiece(0);
	this->_pieceKilled->killed();
	this->_end->setPiece(this->_pieceMoved);
	this->_start->setPiece(0);
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);
	this->_gameStatus->setEnPassantTargetSpot(0);
}

const std::string EnPassantMove::getRepr() const
{
	std::stringstream ss;

	ss << *this->_start << (this->_pieceKilled ? 'x' : '-') << *this->_end << "e.p";
	return ss.str();
}