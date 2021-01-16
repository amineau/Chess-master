/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2021/01/15 23:09:56 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Spot.hpp"
#include <map>
#include <sstream>

class Board {

public:
	Board();
	Board(Board const&);
	~Board();

	Spot* getBox(size_t x, size_t y) const;
	void  setBox(size_t x, size_t y, Spot* spot);
	void  raiseOnInvalidKingNumber() const;

	Board& operator=(Board const&);

	class IndexOutOfBoardException : public std::exception {
	public:
		virtual char const* what() const throw();
	};

	class InvalidNumberOfKingException : public std::exception {
	public:
		virtual char const* what() const throw();
	};

private:
	Spot* _boxes[8][8];
};

std::ostream& operator<<(std::ostream& o, Board const& i);

#endif
