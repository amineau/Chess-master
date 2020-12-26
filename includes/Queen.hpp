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
	Queen( bool isWhite );
	Queen( Queen const & );
	~Queen ();

	bool	canMoves(Board board, Spot start, Spot end) const;

private:
	t_type	_type;
};

#endif
