/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceCLI.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 00:53:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACECLI_HPP
#define USERINTERFACECLI_HPP

#include "UserInterface.hpp"

class UserInterfaceCLI : public UserInterface {
public:
	UserInterfaceCLI();
	UserInterfaceCLI(UserInterfaceCLI const&);
	~UserInterfaceCLI();
	short displayMenu() const;
	void  start();

	UserInterfaceCLI& operator=(UserInterfaceCLI const&);
};

#endif