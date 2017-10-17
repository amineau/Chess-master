/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APiece.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:41:23 by amineau           #+#    #+#             */
/*   Updated: 2017/10/17 22:42:27 by amineau          ###   ########.fr       */
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

typedef struct s_coordinate t_coordinate;
typedef enum e_player       t_player;
typedef enum e_type         t_type;

class APiece {

public:
    APiece( t_type type, int x, int y );
    APiece( APiece const & );
    virtual ~APiece ();

    APiece &    operator=( APiece const & );
    
    t_coodinate const &                 getPosition() const;
    t_player const &                    getPlayer() const;
    t_type const &                      getType() const;
    std::vector<t_coodinate> const &    getMoving() const;
    char                                getXRepresentation() const;
    int                                 getYrepresentation() const;
    void                                setPosition(t_coordinate const &);

    virtual void                        calculMoving() = 0;

    class OutSidePositionException : public std::exception {
    public:
        virtual char const * what() const throw();
    }

protected:
    t_type                      _type;
    t_coodinate                 _position;
    t_player                    _player;
    std::vector<t_coodinate>    _moving;

    
private:

};

std::ostream &   operator<<( std::ostream & o, APiece const & i );

#endif