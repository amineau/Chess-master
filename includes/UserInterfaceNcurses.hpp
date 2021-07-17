/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceNcurses.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/07/17 13:28:39 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACENCURSES_HPP
#define USERINTERFACENCURSES_HPP

#include "UserInterface.hpp"
#include <algorithm>

class UserInterfaceNcurses : public UserInterface {
public:
	UserInterfaceNcurses();
	UserInterfaceNcurses(UserInterfaceNcurses const&);
	~UserInterfaceNcurses();
	short displayMenu() const;
	void  start(const std::string fen);

	void setSelectedSpot(Spot* spot);
	void setOveredSpot(Spot* spot);
	void setDestinationSpots(std::vector<Spot*> spots);

	void printSpot(const short x, const short y, const short colorPair, const char piece) const;
	void displaySpot(const Spot* spot, const unsigned int spotColor = UNDEFINEDCOLOR) const;
	void displayBoard(const Chess& chess) const;

	void displayNewMove(const Move& move, const short moveCounter) const;

	UserInterfaceNcurses& operator=(UserInterfaceNcurses const&);

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