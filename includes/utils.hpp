/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:32:21 by amineau           #+#    #+#             */
/*   Updated: 2022/04/15 23:51:14 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>

int							sgn(int);
std::vector<std::string>	split(std::string str, const char delimiter);
bool					 	isNumber(const std::string&);
const char *				time_to_str(std::filesystem::file_time_type const&);
std::string					readFile(std::filesystem::path path);

#endif