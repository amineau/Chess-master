/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:47:36 by amineau           #+#    #+#             */
/*   Updated: 2017/10/29 13:53:33 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
	: _board(Board())
{
	return;
}

Game::Game( Game const & src )
	: _board(Board())
{
	*this = src;
	return;
}

Game::~Game() {
	return;
}

Game &	Game::operator=( Game const & rhs ) {
	if (this != &rhs) {
		this->_board = rhs._board;
	}
	return *this;
}

/* Accessors */

/* Members functions */

t_position *	Game::_getCoordinate(std::string entry) const {
	t_position * pos;

	if (entry.size() == 2
		&& entry[0] >= 'a' && entry[0] <= 'h'
		&& entry[1] >= '1' && entry[1] <= '8')
	{
		pos = new Position();
		pos->x = entry[0] - 'a';
		pos->y = entry[1] - '1';
		return pos;
	}
	return NULL;
}

void	Game::start() {
	std::vector<std::vector<Piece*> > const &	pieces = this->_board.getBoard();
	Move *	moves;
	t_color	player;
	std::string		entry;
	t_position *	destination;
	t_position *	toMove;
	
	while (1) {
		Destination const *	toGo;
		player = t_color(this->_board.getRound()%2);
		toMove = NULL;
		destination = NULL;		
		std::cout << this->_board;
		while (!toMove) {
			std::cout << "\033[1m[" << color[player] << "]\033[m" << std::endl
				<< "Which piece do you want to play ? : ";
			std::cin >> entry;
			if (!(toMove = this->_getCoordinate(entry)))
				std::cout << "\033[31m" << entry << " is not a valid entry\033[m" << std::endl;
			else if (!pieces[toMove->y][toMove->x] || pieces[toMove->y][toMove->x]->getColor() != player)	
				std::cout << "\033[31mThere is no piece to you on the " <<entry << "\033[m" << std::endl;
			else {
				moves = &pieces[toMove->y][toMove->x]->getMoves();
				if (!moves->getMoves().size())
					std::cout << "\033[31mNo moves possible for this piece\033[m" << std::endl;
				else
					break;
			}
			toMove = NULL;
		}
		while (!destination) {
			std::cout << "Possibles moves :" << std::endl << *moves
				<< "Where do you want to go ? : ";
			std::cin >> entry;
			if (!(destination = this->_getCoordinate(entry)))
				std::cout << "\033[31m" << entry << " is not a valid entry\033[m" << std::endl;
			else if (!(toGo = moves->getDestination(destination->y, destination->x)))	
				std::cout << "\033[31mThe destination is not correct\033[m" << std::endl;
			else
				break;
			destination = NULL;
		}
		std::cout << this->_board.moving(*toGo) << std::endl;
	}
}
