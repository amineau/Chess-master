/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/01/08 19:13:23 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOT_HPP
#define SPOT_HPP

#include <iostream>

class Piece;

class Spot {
public:
	Spot();
	Spot(size_t x, size_t y);
	Spot(size_t x, size_t y, Piece* piece);
	Spot(Spot const& src);
	~Spot();

	size_t getX() const;
	size_t getY() const;
	Piece* getPiece() const;
	void   setPiece(Piece* piece);

	Spot& operator=(Spot const&);
	bool  operator==(Spot const&) const;

private:
	size_t _x;
	size_t _y;
	Piece* _piece;
};

std::ostream& operator<<(std::ostream& o, Spot const& i);

#endif