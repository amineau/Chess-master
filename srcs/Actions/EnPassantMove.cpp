/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnPassantMove.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:47:12 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:28:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actions/EnPassantMove.hpp"
#include "Components/Pieces/Pawn.hpp"

EnPassantMove::EnPassantMove()
	: Move()
{
	return;
}

EnPassantMove::EnPassantMove(GameStatus* gameStatus, Spot* start, Spot* end)
	: Move(gameStatus, start, end)
{
	if (this->_isWhitePlayer)
		this->_spotPieceKilled = gameStatus->getSpot(this->_end->getX(), 4);
	else
		this->_spotPieceKilled = gameStatus->getSpot(this->_end->getX(), 3);
	this->_pieceKilled = this->_spotPieceKilled->getPiece();
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
		this->_spotPieceKilled = rhs._spotPieceKilled;
	}
	return *this;
}

bool EnPassantMove::isLegal() const
{
	Pawn* pawn = dynamic_cast<Pawn*>(this->_pieceMoved);

	return pawn
		&& pawn->getType() == PAWN
		&& pawn->isWhite() == this->_isWhitePlayer
		&& this->_end == this->_gameStatus->getEnPassantTargetSpot()
		&& pawn->canMovesEnPassant(this->_gameStatus, this->_start, this->_end, this->_spotPieceKilled);
}

bool EnPassantMove::execute()
{
	if (!isLegal())
		return false;
	this->executeMove();
	this->_spotPieceKilled->setPiece(0);
	this->_gameStatus->pushTurn();
	this->_gameStatus->pushMove(this);
	this->_gameStatus->setEnPassantTargetSpot(0);
	this->_gameStatus->resetHalfMoveClock();
	return true;
}

EnPassantMove* EnPassantMove::clone() const
{
	return new EnPassantMove(*this);
}

void EnPassantMove::generateRepr()
{
	std::stringstream ss;

	ss << this->_start->getColumn() << 'x' << *this->_end << "e.p";
	this->_repr = ss.str();
}