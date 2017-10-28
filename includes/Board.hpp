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
# include "Pawn.hpp"
# include "Rook.hpp"
# include "Bishop.hpp"
# include "Knight.hpp"
# include "Queen.hpp"
# include "King.hpp"
# include "Move.hpp"
# include "APiece.hpp"

class APieces;

class Board {

public:
	Board();
	Board( Board const & );
	virtual ~Board ();

	Board &	operator=( Board const & );

	std::vector<std::vector<APiece*> > const &	getBoard() const;
	size_t				getRound() const;
	
	std::string const	moving(Destination const & move);
	bool				isCheck();
	void				updateDestinations();
	APiece *			getKing(t_color color);
		
	class UnkownPiecePositionException : public std::exception {
	public:
		virtual char const * what() const throw();
	};

	class KingNotFoundException : public std::exception {
	public:
		virtual char const * what() const throw();
	};
	
private:
	std::vector<std::vector<APiece*> >	_board;
	size_t								_round;
	
	template<typename T>
	void	_init(T t) {
		size_t	nbPiece = BOARD_MAX + 1;
		T *		piece;

		if (t.getType() == ROOK || t.getType() == BISHOP || t.getType() == KNIGHT)
			nbPiece = 2;
		else if (t.getType() == KING || t.getType() == QUEEN)
			nbPiece = 1;
		for (size_t color = 0; color <= 1; color++) {
			for (size_t i = 0; i < nbPiece; i++) {
				piece = new T(i, static_cast<t_color>(color));
				this->_board[piece->getY()][piece->getX()] = piece;
			}		
		}
	}

};

std::ostream &	operator<<( std::ostream & o, Board const & i );

#endif
