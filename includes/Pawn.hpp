/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:09:37 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public virtual Piece {

public:
	Pawn();
	Pawn(bool isWhite);
	Pawn(Pawn const&);
	~Pawn();

	bool canMoves(Board board, Spot start, Spot end) const;

private:
	t_type _type;
};

#endif
