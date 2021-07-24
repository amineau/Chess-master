/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastlingMove.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:46:53 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 23:20:06 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTLINGMOVE_HPP
#define CASTLINGMOVE_HPP

#include "GameStatus.hpp"
#include "Move.hpp"

class CastlingMove : public Move {

public:
	CastlingMove();
	CastlingMove(GameStatus*, Spot* start, Spot* end);
	CastlingMove(CastlingMove const&);
	~CastlingMove();

	bool		  execute();
	CastlingMove* clone() const;

	CastlingMove& operator=(CastlingMove const&);

private:
	void generateRepr();
	bool isLegal() const;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif