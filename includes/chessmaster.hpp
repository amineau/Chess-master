/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chessmaster.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:32:17 by amineau           #+#    #+#             */
/*   Updated: 2021/01/16 01:09:22 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESSMASTER_HPP
#define CHESSMASTER_HPP

#include <curses.h>
#include <getopt.h>
#include <locale.h>
#include <ncurses.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <wchar.h>

#define BLACKSPOTBLACKPIECE 11
#define BLACKSPOTWHITEPIECE 12
#define WHITESPOTBLACKPIECE 13
#define WHITESPOTWHITEPIECE 14
#define SELECTEDSPOTBLACKPIECE 15
#define SELECTEDSPOTWHITEPIECE 16

#define BLACKSPOT 11
#define WHITESPOT 12
#define BLACKPIECE 13
#define WHITEPIECE 14
#define SELECTEDSPOT 15

namespace settings {
extern char* defaultFile;
extern char* defaultInterface;
}

#endif