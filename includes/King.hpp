/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 18:23:09 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KING_HPP
#define KING_HPP

#include "GameStatus.hpp"
#include "Piece.hpp"
#include "Spot.hpp"

class King : public Piece {

public:
	King();
	King(bool isWhite);
	King(King const&);
	~King();

	King& operator=(King const&);

	bool canMovesWithoutCheck(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool canKingSideCastlingMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool canQueenSideCastlingMoves(const GameStatus* gameStatus, const Spot* start, const Spot* end) const;
	bool isCastlingDone() const;
	void setCastlingDone(bool castlingDone);

	std::vector<Spot*> validSpotsWithoutCheck(const GameStatus* gameStatus, const Spot* start) const;

private:
	bool _castlingDone;
};

#endif
