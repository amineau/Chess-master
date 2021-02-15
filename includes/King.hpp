/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:54 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece {

public:
	King();
	King(bool isWhite);
	King(King const&);
	~King();

	King& operator=(King const&);

	bool			   canMoves(GameStatus* gameStatus, Spot* start, Spot* end) const;
	bool			   isCastlingDone() const;
	void			   setCastlingDone(bool castlingDone);
	std::vector<Spot*> validSpots(GameStatus* gameStatus, Spot* start) const;

private:
	bool _castlingDone;
};

#endif
