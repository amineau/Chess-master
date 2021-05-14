/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:31:31 by amineau           #+#    #+#             */
/*   Updated: 2021/05/14 23:56:22 by amineau          ###   ########.fr       */
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

	Action& operator=(Action const&);

protected:
	virtual bool isLegal() const = 0;

	GameStatus* _gameStatus;
	bool		_isWhitePlayer;
};

#endif