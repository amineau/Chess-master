/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleMove.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:46:53 by amineau           #+#    #+#             */
/*   Updated: 2021/07/24 23:19:46 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLEMOVE_HPP
#define SIMPLEMOVE_HPP

#include "GameStatus.hpp"
#include "Move.hpp"

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