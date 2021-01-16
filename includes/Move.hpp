/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2021/01/08 19:13:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
#define MOVE_HPP

#include "Piece.hpp"
#include "Player.hpp"
#include "Spot.hpp"

class Move {

public:
	Move();
	Move(Player* player, Spot* start, Spot* end);
	Move(Move const&);
	~Move();

	Player* getPlayer() const;
	Spot*	getStartSpot() const;
	Spot*	getEndSpot() const;
	Piece*	getPieceMoved() const;
	Piece*	getPieceKilled() const;

	Move& operator=(Move const&);

private:
	Player* _player;
	Spot*	_start;
	Spot*	_end;
	Piece*	_pieceMoved;
	Piece*	_pieceKilled;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif
