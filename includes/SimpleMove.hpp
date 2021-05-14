/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleMove.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:46:53 by amineau           #+#    #+#             */
/*   Updated: 2021/05/15 00:01:02 by amineau          ###   ########.fr       */
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

	bool			  execute();
	const std::string getRepr() const;
	SimpleMove*		  clone() const;

	bool isDoublePushPawn() const;
	void setCastlings();

	SimpleMove& operator=(SimpleMove const&);

private:
	bool isLegal() const;
};

std::ostream& operator<<(std::ostream& o, Move const& i);

#endif