/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterfaceCLI.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/05/18 20:15:35 by amineau          ###   ########.fr       */
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
	void  start(const std::string fen);

	UserInterfaceCLI& operator=(UserInterfaceCLI const&);

private:
	void displayBoard(Chess const& chess) const;
	void end(t_status) const;
};

#endif