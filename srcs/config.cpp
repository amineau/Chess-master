/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:36:58 by amineau           #+#    #+#             */
/*   Updated: 2022/04/15 21:10:49 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.hpp"

namespace settings {
const std::string   defaultFenStart = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
const std::string   defaultInterface = "cli";
const fs::path      backupPath = "./.backup/";
}
