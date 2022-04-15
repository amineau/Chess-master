/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CLI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:02:37 by amineau           #+#    #+#             */
/*   Updated: 2022/04/15 22:38:14 by amineau          ###   ########.fr       */
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
	short chooseBackup(std::vector<std::tuple<int, std::string, const char *>>) const;
	void  start(const std::string fen);

	CLI& operator=(CLI const&);

private:
	void displayBoard(Chess const& chess) const;
	void end(t_status) const;
};

#endif