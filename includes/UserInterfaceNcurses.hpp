/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceNcurses.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 01:12:23 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACENCURSES_HPP
#define USERINTERFACENCURSES_HPP

#include "UserInterface.hpp"

class UserInterfaceNcurses : public UserInterface {
public:
	UserInterfaceNcurses();
	UserInterfaceNcurses(UserInterfaceNcurses const&);
	~UserInterfaceNcurses();
	short displayMenu() const;
	void  start();

	UserInterfaceNcurses& operator=(UserInterfaceNcurses const&);
};

#endif