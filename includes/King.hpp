/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/01/07 15:40:08 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public virtual Piece {

public:
	King();
	King(bool isWhite);
	King(King const&);
	~King();

	King& operator=(King const&);

	bool			   canMoves(Board* board, Spot* start, Spot* end) const;
	bool			   isCastlingDone() const;
	void			   setCastlingDone(bool castlingDone);
	std::vector<Spot*> validSpots(Board* board, Spot* start) const;

private:
	bool _castlingDone;
};

#endif
