/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:11:47 by amineau           #+#    #+#             */
/*   Updated: 2022/04/15 23:51:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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


const char * time_to_str(std::filesystem::file_time_type const& ftime)
{
	std::time_t cftime = std::chrono::system_clock::to_time_t(
		std::chrono::file_clock::to_sys(ftime));
	return std::asctime(std::localtime(&cftime));
}

std::string readFile(std::filesystem::path path)
{
    // Open the stream to 'lock' the file.
    std::ifstream f(path, std::ios::in | std::ios::binary);
    // Obtain the size of the file.
    const auto sz = std::filesystem::file_size(path);
    // Create a buffer.
    std::string result(sz, '\0');
    // Read the whole file into the buffer.
    f.read(result.data(), sz);
    return result;
}
