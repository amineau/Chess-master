/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2017/10/29 00:02:05 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
# define MOVE_HPP

# include <iostream>
# include "Piece.hpp"
# include "Player.hpp"
# include "Spot.hpp"

class Piece;

class Move {

public:
	Move();
	Move(Player * player, Spot *start, Spot *end);
	Move( Move const & );
	~Move ();

	Player const *	getPlayer() const;
	Spot const *	getStartSpot() const;
	Spot const *	getEndSpot() const;
	Piece const *	getPieceMoved() const;
	Piece const *	getPieceKilled() const;

	Move &	operator=( Move const & );

private:
	Player						*_player;
	Spot						*_start;
	Spot						*_end;
	Piece						*_pieceMoved;
	Piece						*_pieceKilled;
};

std::ostream &	operator<<( std::ostream & o, Move const & i );

#endif
