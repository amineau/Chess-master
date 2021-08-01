/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleMove.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:46:53 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:32:56 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLEMOVE_HPP
#define SIMPLEMOVE_HPP

#include "Actions/Move.hpp"
#include "Game/GameStatus.hpp"

class SimpleMove : public Move {

public:
	SimpleMove();
	SimpleMove(GameStatus*, Spot* start, Spot* end);
	SimpleMove(SimpleMove const&);
	~SimpleMove();

	bool		execute();
	SimpleMove* clone() const;

	bool isDoublePushPawn() const;
	void setCastlings();

	SimpleMove& operator=(SimpleMove const&);

private:
	void generateRepr();
	bool isLegal() const;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif