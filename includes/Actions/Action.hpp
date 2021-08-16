/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:31:31 by amineau           #+#    #+#             */
/*   Updated: 2021/08/16 14:31:18 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_HPP
#define ACTION_HPP

class GameStatus;

class Action {
public:
	Action();
	Action(Action const&);
	Action(GameStatus*);
	virtual ~Action();

	virtual bool execute() = 0;
	virtual bool isLegal() const = 0;

	Action& operator=(Action const&);

protected:
	GameStatus* _gameStatus;
	bool		_isWhitePlayer;
};

#endif