/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:41:23 by amineau           #+#    #+#             */
/*   Updated: 2017/10/24 02:16:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APIECE_HPP
# define APIECE_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include "Move.hpp"

# define BOARD_MAX 7

class Move;

enum e_color {
	WHITE, BLACK
};

enum e_type {
	KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
};

typedef enum e_color	t_color;
typedef enum e_type		t_type;

class APiece {
		
public:
	APiece();
	APiece( t_type type );
	APiece( t_type type, e_color color, size_t x, size_t y );
	APiece( APiece const & );
	virtual ~APiece ();
		
	APiece &	operator=( APiece const & );
		
	t_color const &	getColor() const;
	t_type const &	getType() const;
	size_t			getX() const;
	size_t			getY() const;
	char			getXRepresentation() const;
	size_t			getYRepresentation() const;
	void			setPosition(size_t y, size_t x, size_t round);
		
	virtual std::vector<Move> &	getMoving( std::vector<std::vector<APiece*> > const & pieces, size_t round ) = 0;
	
	class PieceOutSidePositionException : public std::exception {
	public:
		virtual char const * what() const throw();
	};
		
protected:

	t_color	_color;
	size_t	_last_move;
	size_t	_x;
	size_t	_y;
		
private:
	t_type	_type;
		
};

std::ostream &	operator<<( std::ostream & o, APiece const & i );

#endif
