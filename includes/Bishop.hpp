/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bishop.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:09:20 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISHOP_HPP
# define BISHOP_HPP

# include "APiece.hpp"

class Bishop : public virtual APiece {

public:
	Bishop();
	Bishop( size_t index, t_color color );
	Bishop( Bishop const & );
	virtual ~Bishop ();

	Bishop &	operator=( Bishop const & );
	virtual Move *	calculMoves( std::vector<std::vector<APiece*> > const &, size_t round );

};

#endif
