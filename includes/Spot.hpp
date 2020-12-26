#ifndef SPOT_HPP
# define SPOT_HPP
# include <iostream>
# include "Piece.hpp"

class Spot
{
public:
    Spot(size_t x, size_t y);
    Spot(size_t x, size_t y, Piece * piece);
    Spot(Spot const & src);
    ~Spot();

    size_t  getX() const;
    size_t  getY() const;
    Piece  *getPiece() const;
    void    setPiece(Piece* piece);

    Spot &  operator=(Spot const &);
    bool    operator==(Spot const &) const;
private:
    size_t  _x;
    size_t  _y;
    Piece  *_piece;
};

#endif