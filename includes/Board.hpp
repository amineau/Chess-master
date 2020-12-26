/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2017/10/28 23:10:49 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
# define BOARD_HPP

# include <sstream>
# include <vector> 
# include "Pawn.hpp"
# include "Rook.hpp"
# include "Bishop.hpp"
# include "Knight.hpp"
# include "Queen.hpp"
# include "King.hpp"
# include "Piece.hpp"
# include "Spot.hpp"

class Pieces;

class Board {

public:
	Board();
	Board( Board const & );
	~Board ();


	Spot *	getBox(size_t x, size_t y);
	void	initialize();
		
	Board &	operator=( Board const & );

	class IndexOutOfBoardException : public std::exception {
	public:
		virtual char const * what() const throw();
	};

private:
	Spot	_boxes[8][8];
};

std::ostream &	operator<<( std::ostream & o, Board const & i );

#endif
