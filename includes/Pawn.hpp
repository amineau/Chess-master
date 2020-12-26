/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:09:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
# define PAWN_HPP

# include "Piece.hpp"

class Pawn : public virtual Piece {

public:
	Pawn();	
	Pawn( bool isWhite );
	Pawn( Pawn const & );
	~Pawn ();

	Pawn &	operator=( Pawn const & );
	
	bool	canMoves(Board board, Spot start, Spot end) const;
};

#endif
