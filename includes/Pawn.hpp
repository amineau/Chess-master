/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2017/10/21 01:21:16 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
# define PAWN_HPP

# include "APiece.hpp"

class Pawn : public APiece {

public:
    Pawn( size_t index, t_color color );
    Pawn( Pawn const & );
    virtual ~Pawn ();

    Pawn &	operator=( Pawn const & );
    virtual std::vector<Move> &   getMoving( std::vector<APiece*> & pieces, size_t round );
    
protected:
private:

};

#endif
