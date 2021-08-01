/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:33:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
#define MOVE_HPP

#include "Actions/Action.hpp"
#include <iostream>

class Piece;
class Spot;

class Move : public Action {

public:
	Move();
	Move(GameStatus* gameStatus, Spot* start, Spot* end);
	Move(Move const&);
	virtual ~Move();

	virtual bool  execute() = 0;
	virtual Move* clone() const = 0;

	const std::string getRepr() const { return _repr; };
	Spot*			  getStartSpot() const { return _start; };
	Spot*			  getEndSpot() const { return _end; };
	Piece*			  getPieceMoved() const { return _pieceMoved; };
	Piece*			  getPieceKilled() const { return _pieceKilled; };

	void executeMove();

	void addStatusChar(const char status);

	Move& operator=(Move const&);

protected:
	Spot*		_start;
	Spot*		_end;
	Piece*		_pieceMoved;
	Piece*		_pieceKilled;
	std::string _repr;

private:
	virtual bool isLegal() const = 0;
	virtual void generateRepr() = 0;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif
