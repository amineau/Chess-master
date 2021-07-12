/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceNcurses.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/07/13 00:47:56 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACENCURSES_HPP
#define USERINTERFACENCURSES_HPP

#include "UserInterface.hpp"

class UserInterfaceNcurses : public UserInterface {
public:
	UserInterfaceNcurses();
	UserInterfaceNcurses(UserInterfaceNcurses const&);
	~UserInterfaceNcurses();
	short displayMenu() const;
	void  start(const std::string fen);

	void displaySpot(const short x, const short y, const Piece* piece) const;
	void displayNewMove(const Move& move, const short moveCounter) const;

	UserInterfaceNcurses& operator=(UserInterfaceNcurses const&);

private:
	WINDOW* _board;
	WINDOW* _blackKilled;
	WINDOW* _whiteKilled;
	WINDOW* _blackInfo;
	WINDOW* _whiteInfo;
	WINDOW* _movePlayed;
};

#endif