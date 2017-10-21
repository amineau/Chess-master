/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:07:59 by amineau           #+#    #+#             */
/*   Updated: 2017/10/22 01:17:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
# define BOARD_HPP

# include "Pawn.hpp"
# include "Rook.hpp"

class Board {

public:
	Board();
	Board( Board const & );
	virtual ~Board ();

	Board &	operator=( Board const & );

	std::vector<APiece*> &	getPieces() const ;

	
private:
	std::vector<APiece*> &	_pieces;
	
	template<typename T>
	void	_init(T t) {
		size_t	nbPiece = BOARD_MAX;

		if (t.getType() == ROOK || t.getType() == BISHOP || t.getType() == KNIGHT)
			nbPiece = 2;
		else if (t.getType() == KING || t.getType() == QUEEN)
			nbPiece = 1;
		std::cout<< nbPiece << std::endl;
		for (size_t color = 0; color <= 1; color++) {
			for (size_t i = 0; i < nbPiece; i++) {
				this->_pieces.push_back(new T(i, static_cast<t_color>(color)));
			}		
		}
	}

};

std::ostream &	operator<<( std::ostream & o, Board const & i );

#endif
