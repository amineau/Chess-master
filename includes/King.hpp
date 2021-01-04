/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/01/04 15:53:20 by amineau          ###   ########.fr       */
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

	bool canMoves(Board* board, Spot* start, Spot* end) const;
	bool isCastlingDone() const;
	void setCastlingDone(bool castlingDone);

private:
	bool _castlingDone;
};

#endif
