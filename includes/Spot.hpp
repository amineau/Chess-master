/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/05/15 00:04:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOT_HPP
#define SPOT_HPP

#include "Piece.hpp"
#include <iostream>

class Spot {
public:
	Spot();
	Spot(size_t x, size_t y);
	Spot(size_t x, size_t y, Piece* piece);
	Spot(Spot const& src);
	~Spot();

	size_t			  getX() const { return _x; }
	size_t			  getY() const { return _y; }
	Piece*			  getPiece() const { return _piece; };
	void			  setPiece(Piece* piece) { _piece = piece; }
	bool			  isEmpty() const { return (_piece == 0); }
	const std::string getRepr() const;

	Spot& operator=(Spot const&);
	bool  operator==(Spot const&) const;

private:
	size_t _x;
	size_t _y;
	Piece* _piece;
};

std::ostream& operator<<(std::ostream& o, Spot const& i);

#endif