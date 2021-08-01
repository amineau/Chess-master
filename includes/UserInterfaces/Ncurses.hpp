/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 17:37:30 by amineau          ###   ########.fr       */
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
	void  start(const std::string fen);

	void setSelectedSpot(Spot* spot);
	void setOveredSpot(Spot* spot);
	void setDestinationSpots(std::vector<Spot*> spots);

	void printSpot(const short x, const short y, const short colorPair, const char* piece) const;
	void displaySpot(const Spot* spot, const unsigned int spotColor = UNDEFINEDCOLOR) const;
	void displayBoard(const Chess& chess) const;

	void displayNewMove(const Move& move, const short moveCounter) const;

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