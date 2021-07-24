/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceNcurses.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:10:57 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 22:32:00 by amineau          ###   ########.fr       */
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
	init_color(OVEREDSPOT, 0, 0, 1000);
	init_color(SELECTEDSPOT, 1000, 0, 0);
	init_color(DESTINATIONSPOT, 0, 1000, 0);

	init_pair(BLACKSPOTBLACKPIECE, BLACKPIECE, BLACKSPOT);
	init_pair(BLACKSPOTWHITEPIECE, WHITEPIECE, BLACKSPOT);
	init_pair(WHITESPOTBLACKPIECE, BLACKPIECE, WHITESPOT);
	init_pair(WHITESPOTWHITEPIECE, WHITEPIECE, WHITESPOT);
	init_pair(OVEREDSPOTBLACKPIECE, BLACKPIECE, OVEREDSPOT);
	init_pair(OVEREDSPOTWHITEPIECE, WHITEPIECE, OVEREDSPOT);
	init_pair(SELECTEDSPOTBLACKPIECE, BLACKPIECE, SELECTEDSPOT);
	init_pair(SELECTEDSPOTWHITEPIECE, WHITEPIECE, SELECTEDSPOT);
	init_pair(DESTINATIONSPOTBLACKPIECE, BLACKPIECE, DESTINATIONSPOT);
	init_pair(DESTINATIONSPOTWHITEPIECE, WHITEPIECE, DESTINATIONSPOT);

	this->_selectedSpot = nullptr;
	this->_overedSpot = nullptr;
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

void UserInterfaceNcurses::setSelectedSpot(Spot* spot)
{
	if (this->_selectedSpot)
		this->displaySpot(this->_selectedSpot);
	this->_selectedSpot = spot;
	if (this->_selectedSpot)
		this->displaySpot(this->_selectedSpot, SELECTEDSPOT);
	else
		this->displaySpot(this->_overedSpot, OVEREDSPOT);
}

void UserInterfaceNcurses::setOveredSpot(Spot* spot)
{
	if (this->_overedSpot) {
		if (this->_overedSpot == this->_selectedSpot)
			this->displaySpot(this->_overedSpot, SELECTEDSPOT);
		else if (std::find(this->_destinationSpots.begin(), this->_destinationSpots.end(), this->_overedSpot) != this->_destinationSpots.end()) {
			this->displaySpot(this->_overedSpot, DESTINATIONSPOT);
		} else
			this->displaySpot(this->_overedSpot);
	}
	this->_overedSpot = spot;
	if (this->_overedSpot) {
		if (this->_overedSpot == this->_selectedSpot)
			this->displaySpot(this->_overedSpot, SELECTEDSPOT);
		else
			this->displaySpot(this->_overedSpot, OVEREDSPOT);
	}
}

void UserInterfaceNcurses::setDestinationSpots(std::vector<Spot*> spots)
{
	for (Spot* spot : this->_destinationSpots)
		this->displaySpot(spot);
	this->_destinationSpots = spots;
	for (Spot* spot : this->_destinationSpots)
		this->displaySpot(spot, DESTINATIONSPOT);
}

void UserInterfaceNcurses::printSpot(const short x, const short y, const short colorPair, const char* piece = " ") const
{
	wattron(this->_board, COLOR_PAIR(colorPair));
	mvwprintw(this->_board, 8 - y, x * 2 + 2, "%s ", piece);
	wattroff(this->_board, COLOR_PAIR(colorPair));
}

void UserInterfaceNcurses::displaySpot(const Spot* spot, unsigned int spotColor) const
{
	unsigned int	   colorPair;
	const Piece*	   piece = spot->getPiece();
	const unsigned int pieceColor = piece && piece->isWhite() ? WHITEPIECE : BLACKPIECE;

	if (spotColor == UNDEFINEDCOLOR)
		spotColor = (spot->getX() + spot->getY()) % 2 ? WHITESPOT : BLACKSPOT;

	colorPair = COLORPAIRMAP[spotColor][pieceColor];
	if (piece)
		this->printSpot(spot->getX(), spot->getY(), colorPair, piece->getUnicodeRepr());
	else
		this->printSpot(spot->getX(), spot->getY(), colorPair);
}

void UserInterfaceNcurses::displayBoard(const Chess& chess) const
{
	for (short x = 0; x < 8; x++)
		for (short y = 0; y < 8; y++)
			this->displaySpot(chess.getSpot(x, y));
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
	Move* move;

	chess.load(fen);
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

	this->displayBoard(chess);

	mvwprintw(this->_blackKilled, 1, 1, "bk");
	mvwprintw(this->_whiteKilled, 1, 1, "wk");
	mvwprintw(this->_blackInfo, 1, 1, "blackInfo");
	mvwprintw(this->_whiteInfo, 1, 1, "whiteInfo");

	int touch;
	this->setOveredSpot(chess.getCurrentPlayer()->isWhite() ? chess.getWhiteSpots().front() : chess.getBlackSpots().front());

	while (1) {

		// mvprintw(0, 0, "Le nombre de lignes est de %d et le nombre de colones est de %d", LINES, COLS);
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

		size_t newX;
		size_t newY;
		if (touch == KEY_RIGHT) {
			newX = (this->_overedSpot->getX() + 1) % 8;
			newY = this->_overedSpot->getY();
			this->setOveredSpot(chess.getSpot(newX, newY));
		}
		if (touch == KEY_LEFT) {
			newX = (this->_overedSpot->getX() - 1) % 8;
			newY = this->_overedSpot->getY();
			this->setOveredSpot(chess.getSpot(newX, newY));
		}
		if (touch == KEY_UP) {
			newX = this->_overedSpot->getX();
			newY = (this->_overedSpot->getY() + 1) % 8;
			this->setOveredSpot(chess.getSpot(newX, newY));
		}
		if (touch == KEY_DOWN) {
			newX = this->_overedSpot->getX();
			newY = (this->_overedSpot->getY() - 1) % 8;
			this->setOveredSpot(chess.getSpot(newX, newY));
		}
		if (touch == 10) {
			if (this->_overedSpot == this->_selectedSpot) {
				this->setSelectedSpot(nullptr);
				this->setDestinationSpots(std::vector<Spot*>());
			} else if (this->_overedSpot->getPiece()
				&& this->_overedSpot->getPiece()->isWhite() == chess.getCurrentPlayer()->isWhite()) {
				mvprintw(1, 1, "%s", this->_overedSpot->getPiece()->getUnicodeRepr());
				this->setSelectedSpot(this->_overedSpot);

				this->setDestinationSpots(chess.validSpots(this->_selectedSpot));
			} else if (std::find(this->_destinationSpots.begin(), this->_destinationSpots.end(), this->_overedSpot) != this->_destinationSpots.end()) {
				move = chess.getMoveAction(this->_selectedSpot, this->_overedSpot);
				chess.makeAction(move);
				this->displayBoard(chess);
				this->displayNewMove(*move, chess.getMoveCounter());
				this->setDestinationSpots(std::vector<Spot*>());
			}
		}
	}

	endwin();
}