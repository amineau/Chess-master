/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 01:33:11 by amineau           #+#    #+#             */
/*   Updated: 2017/10/26 01:31:06 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_HPP
# define MOVE_HPP

# include <iostream>
# include "APiece.hpp"
# include "Destination.hpp"

class APiece;
class Destination;

class Move {

public:
	Move();
	Move( APiece * player );
	Move( Move const & );
	virtual ~Move ();

	void	push(size_t x, size_t y, APiece * target);
	void	push(size_t x, size_t y);
	void	push(Destination dest);

	std::vector<Destination> const &	getMoves() const;
	Destination const &					getDestination(size_t y, size_t x);

	Move &	operator=( Move const & );
	Move	operator+( Move const & ) const;

	class MoveDoesntExistException : public std::exception {
	public:
		virtual char const * what() const throw();
	};

private:
	std::vector<Destination>	_moves;
	APiece *					_player;
};

std::ostream &	operator<<( std::ostream & o, Move const & i );

#endif
