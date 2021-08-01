/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:32:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KING_HPP
#define KING_HPP

#include "Components/Pieces/Piece.hpp"
#include "Components/Spot.hpp"
#include "Game/GameStatus.hpp"

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
