/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2021/05/23 16:05:27 by amineau          ###   ########.fr       */
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

	Spot*			   getSpot(size_t x, size_t y) const;
	Spot*			   getSpot(const std::string& spot) const;
	Spot*			   getSpotKing(bool isWhite) const;
	std::vector<Spot*> getWhiteSpots() const { return _whiteSpots; }
	std::vector<Spot*> getBlackSpots() const { return _blackSpots; }

	void removePiece(Piece*);

	bool			  loadFen(const std::string& fen);
	const std::string exportFen() const;

	void raiseOnInvalidKingNumber() const;

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
	Spot			   _spots[8][8];
	std::vector<Spot*> _whiteSpots;
	std::vector<Spot*> _blackSpots;
	bool			   _isLoad;
};

#endif
