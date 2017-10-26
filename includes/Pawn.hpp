/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pawn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 23:34:32 by amineau           #+#    #+#             */
/*   Updated: 2017/10/26 17:10:16 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAWN_HPP
# define PAWN_HPP

# include "APiece.hpp"

class Pawn : public virtual APiece {

public:
	Pawn();	
	Pawn( size_t index, t_color color );
	Pawn( Pawn const & );
	virtual ~Pawn ();

	Pawn &	operator=( Pawn const & );

	size_t			getLastY() const;
	void			setPosition(size_t y, size_t x, size_t round);	
	virtual Move &	getMoving( std::vector<std::vector<APiece*> > const &, size_t round );

private:
	size_t	_last_y;
};

#endif
