/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 02:06:13 by amineau           #+#    #+#             */
/*   Updated: 2020/12/27 00:21:19 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Player {

public:
	Player();
	Player(bool isWhite);
	Player(Player const&);
	~Player();

	Player& operator=(Player const&);

	bool isWhite(void) const;

private:
	bool _isWhite;
};
