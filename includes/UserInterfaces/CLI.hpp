/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CLI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 17:37:13 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_HPP
#define CLI_HPP

#include "UserInterfaces/UserInterface.hpp"

class CLI : public UserInterface {
public:
	CLI();
	CLI(CLI const&);
	~CLI();
	short displayMenu() const;
	void  start(const std::string fen);

	CLI& operator=(CLI const&);

private:
	void displayBoard(Chess const& chess) const;
	void end(t_status) const;
};

#endif