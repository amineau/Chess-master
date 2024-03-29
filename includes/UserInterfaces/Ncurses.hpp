/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2022/04/15 23:18:33 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "UserInterfaces/UserInterface.hpp"
#include <algorithm>

class Ncurses : public UserInterface {
public:
	Ncurses();
	Ncurses(Ncurses const&);
	~Ncurses();
	short displayMenu() const;
	short chooseBackup(std::vector<std::tuple<int, std::string, const char *>>) const;
	void  start(const std::string fen);

	void setSelectedSpot(Spot* spot);
	void setOveredSpot(Spot* spot);
	void setDestinationSpots(std::vector<Spot*> spots);

	void printSpot(const short x, const short y, const short colorPair, const char* piece) const;
	void displaySpot(const Spot* spot, const unsigned int spotColor = UNDEFINEDCOLOR) const;
	void displayBoard(const Chess& chess) const;

	void displayNewMove(const Move& move, const short moveCounter) const;
	void displayPieceKilled(const Piece& killed) const;

	Ncurses& operator=(Ncurses const&);

private:
	WINDOW* _board;
	WINDOW* _blackKilled;
	WINDOW* _whiteKilled;
	WINDOW* _blackInfo;
	WINDOW* _whiteInfo;
	WINDOW* _movePlayed;

	Spot*			   _selectedSpot;
	Spot*			   _overedSpot;
	std::vector<Spot*> _destinationSpots;
};

#endif
