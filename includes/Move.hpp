/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2021/01/27 19:26:05 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
#define MOVE_HPP

#include "Action.hpp"
#include "Piece.hpp"

class Move : public Action {

public:
	Move();
	Move(GameStatus* gameStatus, Player* player, Spot* start, Spot* end);
	Move(Move const&);
	virtual ~Move();

	virtual const std::string getRepr() const = 0;
	virtual bool			  isLegal() const = 0;
	virtual void			  execute() = 0;

	Spot*  getStartSpot() const;
	Spot*  getEndSpot() const;
	Piece* getPieceMoved() const;
	Piece* getPieceKilled() const;

	Move& operator=(Move const&);

protected:
	Spot*  _start;
	Spot*  _end;
	Piece* _pieceMoved;
	Piece* _pieceKilled;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif
