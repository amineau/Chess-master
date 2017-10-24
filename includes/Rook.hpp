/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rook.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2017/10/24 01:55:14 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOK_HPP
# define ROOK_HPP

# include "APiece.hpp"

class Rook : public virtual APiece {

public:
	Rook();
	Rook( size_t index, t_color color );
	Rook( Rook const & );
	virtual ~Rook ();

	Rook &	operator=( Rook const & );
	virtual std::vector<Move> &   getMoving( std::vector<std::vector<APiece*> > const &, size_t round );

};

#endif
