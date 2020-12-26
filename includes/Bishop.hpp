/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:09:20 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISHOP_HPP
# define BISHOP_HPP

# include "Piece.hpp"

class Bishop : public virtual Piece {

public:
	Bishop();
	Bishop( bool isWhite );
	Bishop( Bishop const & );
	~Bishop ();
	
	bool		canMoves(Board board, Spot start, Spot end) const;

private:
	t_type	_type;
};

#endif
