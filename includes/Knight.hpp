/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:09:35 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public virtual Piece {

public:
	Knight();
	Knight(bool isWhite);
	Knight(Knight const&);
	~Knight();

	bool canMoves(Board board, Spot start, Spot end) const;

private:
	t_type _type;
};

#endif
