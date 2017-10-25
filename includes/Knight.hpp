/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knight.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2017/10/25 21:12:27 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIGHT_HPP
# define KNIGHT_HPP

# include "APiece.hpp"

class Knight : public virtual APiece {

public:
	Knight();
	Knight( size_t index, t_color color );
	Knight( Knight const & );
	virtual ~Knight ();

	Knight &	operator=( Knight const & );
	virtual std::vector<Move> &   getMoving( std::vector<std::vector<APiece*> > const &, size_t round );

};

#endif
