/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:10:03 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public virtual Piece {

public:
	Rook();
	Rook(bool isWhite);
	Rook(Rook const&);
	~Rook();

	bool canMoves(Board board, Spot start, Spot end) const;

private:
	t_type _type;
};

#endif
