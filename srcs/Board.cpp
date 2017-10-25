/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2017/10/25 21:15:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.hpp"

Board::Board()
	: _board(*(new std::vector<std::vector<APiece*> >()))
	, _round(0)
{
	this->_board.resize(BOARD_MAX + 1);
	for (int i = 0; i <= BOARD_MAX; ++i)
    	this->_board[i].resize(BOARD_MAX + 1);
	this->_init(Pawn());
	this->_init(Rook());
	this->_init(Bishop());
	this->_init(Knight());
	return;
}

Board::Board( Board const & src )
	: _board(*(new std::vector<std::vector<APiece*> >()))
	, _round(0)
{
	*this = src;
	return;
}

Board::~Board() {
	// std::vector<APiece*>::iterator it;
	// for (it = this->_pieces.begin(); it != this->_pieces.end(); it++)
	// 	delete &(**it);
	// delete this->_board;
	return;
}

Board &	Board::operator=( Board const & rhs ) {
	if (this != &rhs) {
		this->_board = rhs._board;
	}
	return *this;
}

/* Members functions */

void		Board::moving(APiece * piece, Move & move) {
	if (move.piece)
		delete move.piece;
	this->_board[move.y][move.x] = piece;
	this->_board[piece->getY()][piece->getX()] = NULL;
	piece->setPosition(move.y, move.x, this->_round); 
	this->_round++;
}

/* Accessors */

std::vector<std::vector<APiece*> > const &	Board::getBoard() const {
	return this->_board;
}

/* Operator Overload */

std::ostream &	operator<<( std::ostream & o, Board const & i ) {
	std::vector<std::vector<APiece*> > const & pieces = i.getBoard();

	for (int y = BOARD_MAX; y >= 0; --y) {
		for (int x = 0; x <= BOARD_MAX; ++x){
			if (pieces[y][x])
				o << *(pieces[y][x]) << " ";
			else 
				o << ". ";
		}
		o << std::endl;
	}
	return o;
}

/* Exception */

char const *	Board::UnkownPiecePositionException::what() const throw() {
    return "There is no piece on the target position";
}
