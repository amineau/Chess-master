/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   King.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2017/10/27 20:09:20 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KING_HPP
# define KING_HPP

# include "APiece.hpp"

class King : public virtual APiece {

public:
	King();
	King( size_t index, t_color color );
	King( King const & );
	virtual ~King ();

	King &	operator=( King const & );

	virtual Move *	calculMoves( std::vector<std::vector<APiece*> > const &, size_t round );

};

#endif
