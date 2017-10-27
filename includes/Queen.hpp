/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:09:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEEN_HPP
# define QUEEN_HPP

# include "Bishop.hpp"
# include "Rook.hpp"

class Queen : public Bishop, public Rook {

public:
	Queen();
	Queen( size_t index, t_color color );
	Queen( Queen const & );
	virtual ~Queen ();

	Queen &	operator=( Queen const & );
	virtual Move *	calculMoves( std::vector<std::vector<APiece*> > const &, size_t round );

};

#endif
