/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:09:33 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public virtual Piece {

public:
	Bishop();
	Bishop(bool isWhite);
	Bishop(Bishop const&);
	~Bishop();

	bool canMoves(Board board, Spot start, Spot end) const;

private:
	t_type _type;
};

#endif
