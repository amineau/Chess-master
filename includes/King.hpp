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

	bool canMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool canKingSideCastlingMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool canQueenSideCastlingMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool isCastlingDone() const;
	void setCastlingDone(bool castlingDone);

	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;

private:
	bool _castlingDone;
};

#endif
