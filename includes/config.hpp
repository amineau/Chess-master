/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:32:17 by amineau           #+#    #+#             */
/*   Updated: 2022/04/15 21:10:23 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <curses.h>
#include <getopt.h>
#include <locale.h>
#include <map>
#include <ncurses.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <wchar.h>
#include <filesystem>

#define BLACKSPOTBLACKPIECE 11
#define BLACKSPOTWHITEPIECE 12
#define WHITESPOTBLACKPIECE 13
#define WHITESPOTWHITEPIECE 14
#define OVEREDSPOTBLACKPIECE 15
#define OVEREDSPOTWHITEPIECE 16
#define SELECTEDSPOTBLACKPIECE 17
#define SELECTEDSPOTWHITEPIECE 18
#define DESTINATIONSPOTBLACKPIECE 19
#define DESTINATIONSPOTWHITEPIECE 20

#define UNDEFINEDCOLOR 0
#define BLACKSPOT 11
#define WHITESPOT 12
#define BLACKPIECE 13
#define WHITEPIECE 14
#define OVEREDSPOT 15
#define SELECTEDSPOT 16
#define DESTINATIONSPOT 17

static std::map<int, std::map<int, int>> COLORPAIRMAP = {
	{ BLACKSPOT, { { BLACKPIECE, BLACKSPOTBLACKPIECE }, { WHITEPIECE, BLACKSPOTWHITEPIECE } } },
	{ WHITESPOT, { { BLACKPIECE, WHITESPOTBLACKPIECE }, { WHITEPIECE, WHITESPOTWHITEPIECE } } },
	{ OVEREDSPOT, { { BLACKPIECE, OVEREDSPOTBLACKPIECE }, { WHITEPIECE, OVEREDSPOTWHITEPIECE } } },
	{ SELECTEDSPOT, { { BLACKPIECE, SELECTEDSPOTWHITEPIECE }, { WHITEPIECE, SELECTEDSPOTWHITEPIECE } } },
	{ DESTINATIONSPOT, { { BLACKPIECE, DESTINATIONSPOTBLACKPIECE }, { WHITEPIECE, DESTINATIONSPOTWHITEPIECE } } },
};

namespace fs = std::filesystem;

namespace settings {
extern const std::string	defaultFenStart;
extern const std::string	defaultInterface;
extern const fs::path		backupPath;
}

#endif