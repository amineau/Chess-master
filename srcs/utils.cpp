/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2021/01/20 00:42:23 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#include <iostream>

int sgn(int valeur)
{
	if (valeur < 0)
		return -1;
	if (valeur == 0)
		return 0;
	return 1;
}

std::vector<std::string> split(std::string str, const char delimiter)
{
	std::vector<std::string> vec;
	size_t					 pos = 0;

	while ((pos = str.find(delimiter)) != std::string::npos) {
		vec.push_back(str.substr(0, pos));
		str.erase(0, pos + 1);
	}
	vec.push_back(str);
	return vec;
}

bool isNumber(const std::string& str)
{
	for (auto it = str.cbegin(); it != str.cend(); ++it)
		if (!std::isdigit(*it))
			return false;
	return true;
}