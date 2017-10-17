/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:41:23 by amineau           #+#    #+#             */
/*   Updated: 2017/10/18 00:02:01 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APIECE_HPP
# define APIECE_HPP

# include <iostream>
# include <algorithm>

struct s_coordinate {
    int x;
    int y;
};

enum e_player {
    WHITE, BLACK
};

enum e_type {
    KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
};

typedef struct s_coordinate         t_coordinate;
typedef enum e_player               t_player;
typedef enum e_type                 t_type;
typedef std::vector<t_coordinate>   t_moving;

class APiece {
    
public:
    APiece( t_type type, int x, int y );
    APiece( APiece const & );
    virtual ~APiece ();
    
    APiece &    operator=( APiece const & );
    
    t_coordinate const &                getPosition() const;
    t_player const &                    getPlayer() const;
    t_type const &                      getType() const;
    char                                getXRepresentation() const;
    int                                 getYRepresentation() const;
    void                                setPosition(t_coordinate const &);
    
    typedef std::vector<APiece*>        t_board_game;
    virtual t_moving                    getMoving(t_board_game const & ) = 0;

    class OutSidePositionException : public std::exception {
    public:
        virtual char const * what() const throw();
    };

protected:
    t_type                      _type;
    t_coordinate                 _position;
    t_player                    _player;
    
private:

};

std::ostream &   operator<<( std::ostream & o, APiece const & i );

#endif