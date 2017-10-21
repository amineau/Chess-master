/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 01:36:24 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
# define MOVE_HPP

# include <iostream>
# include "APiece.hpp"

class APiece;

class Move {

public:
    Move(size_t x, size_t y, APiece * piece);
    Move( Move const & );
    virtual ~Move ();

    Move &	operator=( Move const & );

    size_t    x;
    size_t    y;
    APiece *  piece;

    class MoveOutSidePositionException : public std::exception {
    public:
        virtual char const * what() const throw();
    };
};

#endif
