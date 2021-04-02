/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2021/01/28 06:54:55 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Spot.hpp"
#include <array>
#include <map>
#include <sstream>

class Board {

public:
	Board();
	Board(Board const&);
	~Board();

	Spot* getSpot(size_t x, size_t y) const;
	Spot* getSpot(const std::string& spot) const;
	void  raiseOnInvalidKingNumber() const;

	Spot* getSpotKing(bool isWhite) const;

	bool			  loadFen(const std::string& fen);
	const std::string exportFen() const;

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
	Spot _spots[8][8];
	bool _isLoad;
};

#endif
