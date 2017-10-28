/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:46:32 by amineau           #+#    #+#             */
/*   Updated: 2017/10/28 23:35:35 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include "Board.hpp"

struct Position {
	size_t x;
	size_t y;
};

typedef struct Position t_position;

class Game {

public:
	Game();
	Game( Game const & );
	virtual ~Game();

	void	start();
	void	end();

	Game &	operator=( Game const & );

private:
	Board	_board;

	t_position *	_getCoordinate(std::string entry) const;
		

};

#endif
