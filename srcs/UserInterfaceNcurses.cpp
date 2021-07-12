/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceNcurses.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:57 by amineau           #+#    #+#             */
/*   Updated: 2021/07/13 00:56:03 by amineau          ###   ########.fr       */
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
	// char entry = 0;

	// while (entry != '1' && entry != '2' && entry != '3') {
	// 	if (entry != 0)
	// 		std::cout << "Enter a valid choice" << std::endl;
	// 	std::cout << "1/ Start new chess" << std::endl
	// 			  << "2/ Load chess" << std::endl
	// 			  << "3/ Quit" << std::endl
	// 			  << "Enter the option number : ";
	// 	std::cin >> entry;
	// }

	// return entry - '0';
	return 1;
}

void UserInterfaceNcurses::displaySpot(const short x, const short y, const Piece* piece) const
{
	short	   colorPair;
	const bool spotIsWhite = (x + y) % 2 == 0;

	if (piece && piece->isWhite())
		colorPair = spotIsWhite ? WHITESPOTWHITEPIECE : BLACKSPOTWHITEPIECE;
	else
		colorPair = spotIsWhite ? WHITESPOTBLACKPIECE : BLACKSPOTBLACKPIECE;

	wattron(this->_board, COLOR_PAIR(colorPair));
	if (piece)
		mvwprintw(this->_board, 8 - y, x * 2 + 2, "%lc ", piece->getRepr());
	else
		mvwprintw(this->_board, 8 - y, x * 2 + 2, "  ");
	wattroff(this->_board, COLOR_PAIR(colorPair));
}

void UserInterfaceNcurses::displayNewMove(const Move& move, const short moveCounter) const
{
	if (move.getPieceMoved()->isWhite())
		wprintw(this->_movePlayed, "%d. %s", moveCounter, move.getRepr().c_str());
	else {
		wprintw(this->_movePlayed, " %s\n", move.getRepr().c_str());
	}
}

void UserInterfaceNcurses::start(const std::string fen)
{
	Chess chess = Chess();

	if (!chess.load(fen)) {
		std::cout << "Wrong parsing" << std::endl;
		exit(EXIT_FAILURE);
	}

	this->_board = subwin(stdscr, 10, 20, 6, 14);
	this->_blackKilled = subwin(stdscr, 5, 8, 6, 3);
	this->_whiteKilled = subwin(stdscr, 5, 8, 11, 3);
	this->_blackInfo = subwin(stdscr, 4, 20, 2, 14);
	this->_whiteInfo = subwin(stdscr, 4, 20, 16, 14);
	this->_movePlayed = subwin(stdscr, 18, 16, 2, 36);

	scrollok(this->_movePlayed, TRUE);

	// box(board, ACS_VLINE, ACS_HLINE);
	box(this->_blackKilled, ACS_VLINE, ACS_HLINE);
	box(this->_whiteKilled, ACS_VLINE, ACS_HLINE);
	box(this->_blackInfo, ACS_VLINE, ACS_HLINE);
	box(this->_whiteInfo, ACS_VLINE, ACS_HLINE);
	box(this->_movePlayed, ACS_VLINE, ACS_HLINE);

	for (short lineNumber = 8; lineNumber > 0; lineNumber--) {
		mvwaddch(this->_board, 9 - lineNumber, 0, '0' + lineNumber);
	}
	for (short colNumber = 0; colNumber < 8; colNumber++)
		mvwprintw(this->_board, 9, 2 + colNumber * 2, "%c ", colNumber + 'a');

	for (short x = 0; x < 8; x++)
		for (short y = 0; y < 8; y++)
			this->displaySpot(x, y, chess.getPiece(x, y));

	mvwprintw(this->_blackKilled, 1, 1, "bk");
	mvwprintw(this->_whiteKilled, 1, 1, "wk");
	mvwprintw(this->_blackInfo, 1, 1, "blackInfo");
	mvwprintw(this->_whiteInfo, 1, 1, "whiteInfo");

	int touch;

	while (1) {

		mvprintw(0, 0, "Le nombre de lignes est de %d et le nombre de colones est de %d", LINES, COLS);
		wrefresh(this->_board);
		wrefresh(this->_blackKilled);
		wrefresh(this->_whiteKilled);
		wrefresh(this->_blackInfo);
		wrefresh(this->_whiteInfo);
		wrefresh(this->_movePlayed);
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