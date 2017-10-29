/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:41:23 by amineau           #+#    #+#             */
/*   Updated: 2017/10/29 02:11:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APIECE_HPP
# define APIECE_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
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

static std::pair<int, const char*> map_type[] = {
    std::make_pair(KING, "\u265A"),
	std::make_pair(QUEEN, "\u265B"),
    std::make_pair(ROOK, "\u265C"),
    std::make_pair(BISHOP, "\u265D"),
    std::make_pair(KNIGHT, "\u265E"),
    std::make_pair(PAWN, "\u265F")
};

static std::map<int, const char*> type(map_type,
	map_type + sizeof map_type / sizeof map_type[0]);
	
static std::pair<int, const char*> map_color[] = {
	std::make_pair(WHITE, "WHITE"),
	std::make_pair(BLACK, "BLACK")
};
	
static std::map<int, const char*> color(map_color,
	map_color + sizeof map_color / sizeof map_color[0]);



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
	size_t			getLastMove() const;
	char			getXRepresentation() const;
	size_t			getYRepresentation() const;
	Move &			getMoves() const;
	void			update( std::vector<std::vector<APiece*> > const & pieces, size_t round );
	virtual void	setPosition(size_t y, size_t x, size_t round);
	
	virtual Move *	calculMoves( std::vector<std::vector<APiece*> > const & pieces, size_t round ) = 0;
	
	class PieceOutSidePositionException : public std::exception {
	public:
		virtual char const * what() const throw();
	};
		
protected:

	t_color	_color;
	size_t	_last_move;
	size_t	_x;
	size_t	_y;
	Move *	_moves;

private:
	t_type	_type;
		
};

std::ostream &	operator<<( std::ostream & o, APiece const & i );

#endif
