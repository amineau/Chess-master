/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2021/05/23 16:08:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
#define MOVE_HPP

#include "Action.hpp"
#include <iostream>

class Piece;
class Spot;

class Move : public Action {

public:
	Move();
	Move(GameStatus* gameStatus, Spot* start, Spot* end);
	Move(Move const&);
	virtual ~Move();

	virtual const std::string getRepr() const = 0;
	virtual bool			  execute() = 0;
	virtual Move*			  clone() const = 0;

	Spot*  getStartSpot() const { return _start; };
	Spot*  getEndSpot() const { return _end; };
	Piece* getPieceMoved() const { return _pieceMoved; };
	Piece* getPieceKilled() const { return _pieceKilled; };

	void executeMove();

	Move& operator=(Move const&);

protected:
	Spot*  _start;
	Spot*  _end;
	Piece* _pieceMoved;
	Piece* _pieceKilled;

private:
	virtual bool isLegal() const = 0;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif
