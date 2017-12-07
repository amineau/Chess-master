/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2017/12/07 07:38:16 by amineau          ###   ########.fr       */
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
	this->_init(Queen());
	this->_init(King());
	this->updateDestinations();
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

/* Members functions */

std::string	const 	Board::moving(Destination const & move) {
	APiece *	piece = move.getPlayer();
	APiece *	target = move.getTarget();
	std::ostringstream	buffer;
	
	if (target) {
		this->_board[target->getY()][target->getX()] = NULL;
		delete target;
	}
	if (piece->getType() == KING) {
		if (move.x == piece->getX() + 2) {
			this->moving(Destination(piece->getX() + 1, move.y, this->_board[move.y][BOARD_MAX]));
			this->_round--;
		} else if (move.x == piece->getX() - 2) {
			this->moving(Destination(piece->getX() - 1, move.y, this->_board[move.y][0]));
			this->_round--;
		}
	}
	this->_board[move.y][move.x] = piece;
	this->_board[piece->getY()][piece->getX()] = NULL;
	piece->setPosition(move.y, move.x, this->_round++); 
	buffer << move;
	if (this->isCheck())
		buffer << "+";
	this->updateDestinations();
	return buffer.str();
}

APiece *	Board::getKing(t_color color) {
	std::vector<std::vector<APiece*> >::const_iterator	row;
	std::vector<APiece*>::const_iterator					it;

	for (row = this->_board.begin(); row != this->_board.end(); row++)
		for (it = row->begin(); it != row->end(); it++)
			if (*it && (*it)->getType() == KING && (*it)->getColor() == color)
				return &(**it);
	throw Board::KingNotFoundException();
}

bool		Board::isCheck() {
	std::vector<std::vector<APiece*> >::iterator	row;
	std::vector<APiece*>::iterator					it;
	std::vector<Destination>::const_iterator		dest;
	APiece *										king;
	bool											isCheck;
	t_color											player;
	t_color											opponent;

	player = t_color(this->_round%2);
	opponent = t_color((this->_round + 1)%2);
	king = this->getKing(player);
	isCheck = false;
	for (row = this->_board.begin(); row != this->_board.end(); row++) {
		for (it = row->begin(); it != row->end(); it++) {
			if (*it && (*it)->getColor() == opponent) {
				(*it)->update(this->_board, this->_round);
				for (dest = (*it)->getMoves().getMoves().begin(); dest != (*it)->getMoves().getMoves().end(); dest++) {
					if (dest->getTarget() == king)
						isCheck = true;
				}
			}
		}
	}
	return isCheck;
}

void		Board::updateDestinations() {
	std::vector<std::vector<APiece*> >::iterator	row;
	std::vector<APiece*>::iterator					it;
	t_color											player;

	player = t_color(this->_round%2);
	for (row = this->_board.begin(); row != this->_board.end(); row++)
		for (it = row->begin(); it != row->end(); it++)
			if (*it && (*it)->getColor() == player)
				(*it)->update(this->_board, this->_round);
}



/* Accessors */

std::vector<std::vector<APiece*> > const &	Board::getBoard() const {
	return this->_board;
}

size_t				Board::getRound() const {
	return this->_round;
}


/* Operator Overload */

Board &	Board::operator=( Board const & rhs ) {
	if (this != &rhs) {
		this->_board = rhs._board;
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Board const & i ) {
	std::vector<std::vector<APiece*> > const & pieces = i.getBoard();
	o << "\033[38;5;232;48;5;215m                    \033[0m" << std::endl;
	for (int y = BOARD_MAX; y >= 0; --y) {
		o << "\033[38;5;232;48;5;215m" << y + 1 << " ";		
		for (int x = 0; x <= BOARD_MAX; ++x){
			if ((y + x) % 2)
				o << "\033[48;5;255m";
			else
				o << "\033[48;5;75m";
			if (pieces[y][x])
			{
				if (pieces[y][x]->getColor() == BLACK)
					o << "\033[1;38;5;232m";
				else
					o << "\033[1;38;5;22m";
				o << *(pieces[y][x]) << " ";
			}
			else 
				o << "  ";
		}
		o << "\033[38;5;232;48;5;215m  \033[0m" << std::endl;
	}
	o << "\033[38;5;232;48;5;215m  a b c d e f g h   \033[0m" << std::endl;	
	return o;
}

/* Exception */

char const *	Board::UnkownPiecePositionException::what() const throw() {
    return "There is no piece on the target position";
}

char const *	Board::KingNotFoundException::what() const throw() {
    return "King not found";
}
