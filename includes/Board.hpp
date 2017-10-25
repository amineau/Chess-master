/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2017/10/26 00:00:54 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
# define BOARD_HPP

# include "Pawn.hpp"
# include "Rook.hpp"
# include "Bishop.hpp"
# include "Knight.hpp"
# include "Move.hpp"

class Board {

public:
	Board();
	Board( Board const & );
	virtual ~Board ();

	Board &	operator=( Board const & );

	std::vector<std::vector<APiece*> > const &	getBoard() const;
	void	moving(Destination const & move);
		
	class UnkownPiecePositionException : public std::exception {
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
