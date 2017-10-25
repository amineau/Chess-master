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
# include "APiece.hpp"

class APiece;

class Destination {

public:
	Destination(size_t x, size_t y, APiece * player, APiece * target);
	Destination(size_t x, size_t y, APiece * player);
	Destination( Destination const & );
	virtual ~Destination ();

	APiece *	getTarget() const;
	APiece *	getPlayer() const;

	Destination &	operator=( Destination const & );

	size_t		x;
	size_t		y;

	class DestinationOutSidePositionException : public std::exception {
	public:
		virtual char const * what() const throw();
	};

private:
	APiece *	_target;
	APiece *	_player;

};

#endif
