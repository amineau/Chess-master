/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2021/02/15 22:08:39 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Player {

public:
	Player();
	Player(bool isWhite);
	Player(Player const&);
	~Player();

	Player& operator=(Player const&);
	bool	operator==(Player const&);

	bool isWhite(void) const;

private:
	bool _isWhite;
};

std::ostream& operator<<(std::ostream& o, Player const& i);

#endif