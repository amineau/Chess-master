/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Destination.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2017/10/25 22:27:25 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_HPP
# define COORDINATE_HPP

# include <iostream>
# include "Piece.hpp"

class Piece;

class Destination {

public:
	Destination(size_t x, size_t y, Piece * player, Piece * target);
	Destination(size_t x, size_t y, Piece * player);
	Destination( Destination const & );
	virtual ~Destination ();

	Piece *	getTarget() const;
	Piece *	getPlayer() const;

	Destination &	operator=( Destination const & );

	size_t		x;
	size_t		y;

	class DestinationOutSidePositionException : public std::exception {
	public:
		virtual char const * what() const throw();
	};

private:
	Piece *	_target;
	Piece *	_player;

};

std::ostream &	operator<<( std::ostream & o, Destination const & i );

#endif
