/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exporter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:18:30 by amineau           #+#    #+#             */
/*   Updated: 2021/01/23 00:28:07 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORTER_HPP
#define EXPORTER_HPP

#include "GameStatus.hpp"

class Exporter {
public:
	Exporter();
	Exporter(Exporter const&);
	Exporter(GameStatus*);
	~Exporter();

	const std::string fen() const;

	Exporter& operator=(Exporter const&);

private:
	const std::string _fenBoard() const;
	const std::string _fenCurrentPlayer() const;
	const std::string _fenCastlingsAvailable() const;
	const std::string _fenEnPassantTargetSpot() const;
	const std::string _fenHalfMoveClock() const;
	const std::string _fenFullMoveCounter() const;

	GameStatus* _gameStatus;
};

#endif