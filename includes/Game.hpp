/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:46:32 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 01:10:40 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Move.hpp"
#include "Player.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class Game {

public:
	Game();
	Game(Game const&);
	~Game();

	Board*			  getBoard() const;
	void			  setBoard(Board* board);
	Player*			  getCurrentTurn() const;
	void			  setCurrentTurn(Player* player);
	std::vector<Move> getMovesPlayed() const;
	Player*			  getPlayerWhite() const;
	Player*			  getPlayerBlack() const;

	void load(const char* file);
	void exporter(const char* file);

	bool playerMoved(Player* player, size_t startX, size_t startY, size_t endX, size_t endY);
	bool makeMove(Player* player, Move move);

	Game& operator=(Game const&);

	class ParsingFileException : public std::exception {
	public:
		ParsingFileException(size_t line) throw();
		ParsingFileException(size_t line, size_t column) throw();
		virtual char const* what() const throw();

	private:
		std::string _message;
	};

private:
	Board*			  _board;
	Player*			  _currentTurn;
	Player*			  _playerWhite;
	Player*			  _playerBlack;
	std::vector<Move> _movesPlayed;
};

std::istream& operator>>(std::istream& is, Game& game);

#endif
