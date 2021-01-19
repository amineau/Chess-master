/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceNcurses.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:57 by amineau           #+#    #+#             */
/*   Updated: 2021/01/20 00:25:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterfaceNcurses.hpp"

UserInterfaceNcurses::UserInterfaceNcurses()
{
	initscr();
	noecho();
	cbreak();

	// Enables keypad mode. This makes (at least for me) mouse events getting
	// reported as KEY_MOUSE, instead as of random letters.
	keypad(stdscr, TRUE);

	// Don't mask any mouse events
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

	if (has_colors() == FALSE || can_change_color() == FALSE) {
		endwin();
		std::cout << "Your terminal does not support color" << std::endl;
		exit(1);
	}

	start_color();
	init_color(BLACKSPOT, 843, 525, 0);
	init_color(WHITESPOT, 1000, 686, 373);
	init_color(BLACKPIECE, 0, 0, 0);
	init_color(WHITEPIECE, 1000, 1000, 1000);

	init_pair(BLACKSPOTBLACKPIECE, BLACKPIECE, BLACKSPOT);
	init_pair(BLACKSPOTWHITEPIECE, WHITEPIECE, BLACKSPOT);
	init_pair(WHITESPOTBLACKPIECE, BLACKPIECE, WHITESPOT);
	init_pair(WHITESPOTWHITEPIECE, WHITEPIECE, WHITESPOT);
	init_pair(SELECTEDSPOTBLACKPIECE, BLACKPIECE, SELECTEDSPOT);
	init_pair(SELECTEDSPOTWHITEPIECE, WHITEPIECE, SELECTEDSPOT);
	return;
}

UserInterfaceNcurses::UserInterfaceNcurses(UserInterfaceNcurses const& src)
{
	*this = src;
	return;
}

UserInterfaceNcurses::~UserInterfaceNcurses()
{
	return;
}

UserInterfaceNcurses& UserInterfaceNcurses::operator=(UserInterfaceNcurses const& rhs)
{
	if (this != &rhs)
		this->_chess = rhs._chess;
	return *this;
}

short UserInterfaceNcurses::displayMenu() const
{
	char entry = 0;

	while (entry != '1' && entry != '2' && entry != '3') {
		if (entry != 0)
			std::cout << "Enter a valid choice" << std::endl;
		std::cout << "1/ Start new chess" << std::endl
				  << "2/ Load chess" << std::endl
				  << "3/ Quit" << std::endl
				  << "Enter the option number : ";
		std::cin >> entry;
	}

	return entry - '0';
}
void UserInterfaceNcurses::start()
{
	WINDOW *board, *blackKilled, *whiteKilled, *blackInfo, *whiteInfo, *movePlayed;
	this->_chess = Chess();
	if (!this->_chess.load_fen(settings::defaultFenStart)) {
		std::cout << "Wrong parsing";
		exit(EXIT_FAILURE);
	}

	board = subwin(stdscr, 10, 20, 4, 8);
	blackKilled = subwin(stdscr, 5, 4, 4, 4);
	whiteKilled = subwin(stdscr, 5, 4, 9, 4);
	blackInfo = subwin(stdscr, 2, 20, 2, 8);
	whiteInfo = subwin(stdscr, 2, 20, 14, 8);
	movePlayed = subwin(stdscr, 14, 12, 2, 32);

	// box(board, ACS_VLINE, ACS_HLINE);
	box(blackKilled, ACS_VLINE, ACS_HLINE);
	box(whiteKilled, ACS_VLINE, ACS_HLINE);
	box(blackInfo, ACS_VLINE, ACS_HLINE);
	box(whiteInfo, ACS_VLINE, ACS_HLINE);
	box(movePlayed, ACS_VLINE, ACS_HLINE);

	for (short lineNumber = 8; lineNumber > 0; lineNumber--) {
		mvwaddch(board, 9 - lineNumber, 0, '0' + lineNumber);
	}
	for (short colNumber = 0; colNumber < 8; colNumber++)
		mvwprintw(board, 9, 2 + colNumber * 2, "%c ", colNumber + 'a');

	for (short x = 0; x < 8; x++) {
		for (short y = 0; y < 8; y++) {
			if ((x + y) % 2 == 0) {
				if (this->_chess.getBoard()->getBox(x, y)->getPiece())
					if (this->_chess.getBoard()->getBox(x, y)->getPiece()->isWhite()) {
						wattron(board, COLOR_PAIR(BLACKSPOTWHITEPIECE));
						mvwprintw(board, 8 - y, x * 2 + 2, "%lc ", this->_chess.getBoard()->getBox(x, y)->getPiece());
						wattroff(board, COLOR_PAIR(BLACKSPOTWHITEPIECE));
					} else {
						wattron(board, COLOR_PAIR(BLACKSPOTBLACKPIECE));
						mvwprintw(board, 8 - y, x * 2 + 2, "%lc ", this->_chess.getBoard()->getBox(x, y)->getPiece());
						wattroff(board, COLOR_PAIR(BLACKSPOTBLACKPIECE));
					}
				else {
					wattron(board, COLOR_PAIR(BLACKSPOTBLACKPIECE));
					mvwprintw(board, 8 - y, x * 2 + 2, "  ");
					wattroff(board, COLOR_PAIR(BLACKSPOTBLACKPIECE));
				}
			} else {
				if (this->_chess.getBoard()->getBox(x, y)->getPiece())
					if (this->_chess.getBoard()->getBox(x, y)->getPiece()->isWhite()) {
						wattron(board, COLOR_PAIR(WHITESPOTWHITEPIECE));
						mvwprintw(board, 8 - y, x * 2 + 2, "%lc ", this->_chess.getBoard()->getBox(x, y)->getPiece());
						wattroff(board, COLOR_PAIR(WHITESPOTWHITEPIECE));
					} else {
						wattron(board, COLOR_PAIR(WHITESPOTBLACKPIECE));
						mvwprintw(board, 8 - y, x * 2 + 2, "%lc ", this->_chess.getBoard()->getBox(x, y)->getPiece());
						wattroff(board, COLOR_PAIR(WHITESPOTBLACKPIECE));
					}
				else {
					wattron(board, COLOR_PAIR(WHITESPOTBLACKPIECE));
					mvwprintw(board, 8 - y, x * 2 + 2, "  ");
					wattroff(board, COLOR_PAIR(WHITESPOTBLACKPIECE));
				}
			}
		}
	}

	mvwprintw(blackKilled, 1, 1, "bk");
	mvwprintw(whiteKilled, 1, 1, "wk");
	mvwprintw(blackInfo, 1, 1, "blackInfo");
	mvwprintw(whiteInfo, 1, 1, "whiteInfo");
	mvwprintw(movePlayed, 1, 1, "movePlayed");
	int touch;

	while (1) {

		// mvprintw(0, 0, "Les nombre de lignes est de %d et le nombre de colones est de %d", LINES, COLS);
		wrefresh(board);
		wrefresh(blackKilled);
		wrefresh(whiteKilled);
		wrefresh(blackInfo);
		wrefresh(whiteInfo);
		wrefresh(movePlayed);
		refresh();
		touch = getch();
		if (touch != 410)
			mvprintw(0, 0, "%0.4d", touch);

		if (touch == KEY_MOUSE) {
			MEVENT event;
			if (getmouse(&event) == OK) {
				mvprintw(1, 0, "Mouse at row=%d, column=%d bstate=0x%08x",
					event.y, event.x, event.bstate);
			} else {
				mvprintw(1, 0, "Got bad mouse event.");
			}
		}
	}

	endwin();
}