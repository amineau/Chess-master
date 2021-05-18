/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:30:33 by amineau           #+#    #+#             */
/*   Updated: 2021/05/18 23:57:12 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "Chess.hpp"
#include "catch.hpp"

TEST_CASE("Move piece check")
{
	Chess chess = Chess();
	Move* move;
	SECTION("Pawn moves")
	{
		SECTION("Pawn can push one from start")
		{
			SECTION("White side")
			{
				Piece* pawn;
				chess.load("8/8/8/8/8/8/P7/2k1K3 w - - 0 1");

				pawn = chess.getPiece("a2");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == true);

				move = chess.getMoveAction("a2", "a3");

				REQUIRE(chess.makeAction(move) == true);
				REQUIRE(chess.getPiece("a3") == pawn);
			}
			SECTION("Black side")
			{
				Piece* pawn;
				chess.load("8/p7/8/8/8/8/8/2k1K3 b - - 0 1");

				pawn = chess.getPiece("a7");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == false);

				move = chess.getMoveAction("a7", "a6");

				REQUIRE(chess.makeAction(move) == true);
				REQUIRE(chess.getPiece("a6") == pawn);
			}
		}
		SECTION("Pawn can push one")
		{
			SECTION("White side")
			{
				Piece* pawn;
				chess.load("8/8/8/8/8/P7/8/2k1K3 w - - 0 1");

				pawn = chess.getPiece("a3");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == true);

				move = chess.getMoveAction("a3", "a4");

				REQUIRE(chess.makeAction(move) == true);
				REQUIRE(chess.getPiece("a4") == pawn);
			}
			SECTION("Black side")
			{
				Piece* pawn;
				chess.load("8/8/p7/8/8/8/8/2k1K3 b - - 0 1");

				pawn = chess.getPiece("a6");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == false);

				move = chess.getMoveAction("a6", "a5");

				REQUIRE(chess.makeAction(move) == true);
				REQUIRE(chess.getPiece("a5") == pawn);
			}
		}
		SECTION("Pawn can double push one from start")
		{
			SECTION("White side")
			{
				Piece* pawn;
				chess.load("8/8/8/8/8/8/P7/2k1K3 w - - 0 1");

				pawn = chess.getPiece("a2");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == true);

				move = chess.getMoveAction("a2", "a4");

				REQUIRE(chess.makeAction(move) == true);
				REQUIRE(chess.getPiece("a4") == pawn);
			}
			SECTION("Black side")
			{
				Piece* pawn;
				chess.load("8/p7/8/8/8/8/8/2k1K3 b - - 0 1");

				pawn = chess.getPiece("a7");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == false);

				move = chess.getMoveAction("a7", "a5");

				REQUIRE(chess.makeAction(move) == true);
				REQUIRE(chess.getPiece("a5") == pawn);
			}
		}
		SECTION("Pawn cant double push one from not start position")
		{
			SECTION("White side")
			{
				Piece* pawn;
				chess.load("8/8/8/8/8/P7/8/2k1K3 w - - 0 1");

				pawn = chess.getPiece("a3");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == true);

				move = chess.getMoveAction("a3", "a5");

				REQUIRE(chess.makeAction(move) == false);
				REQUIRE(chess.getPiece("a3") == pawn);
			}
			SECTION("Black side")
			{
				Piece* pawn;
				chess.load("8/8/p7/8/8/8/8/2k1K3 b - - 0 1");

				pawn = chess.getPiece("a6");
				REQUIRE(pawn->getType() == PAWN);
				REQUIRE(pawn->isWhite() == false);

				move = chess.getMoveAction("a6", "a4");

				REQUIRE(chess.makeAction(move) == false);
				REQUIRE(chess.getPiece("a6") == pawn);
			}
		}
		SECTION("Pawn capture")
		{
			Piece* pawn;
			chess.load("8/8/8/8/8/1p6/P7/2k1K3 w - - 0 1");

			pawn = chess.getPiece("a2");
			REQUIRE(pawn->getType() == PAWN);
			REQUIRE(pawn->isWhite() == true);

			move = chess.getMoveAction("a2", "b3");

			REQUIRE(chess.makeAction(move) == true);
			REQUIRE(chess.getPiece("b3") == pawn);
			REQUIRE(chess.getPiece("b3")->isWhite() == true);
			REQUIRE(chess.getBlackSpots().size() == 1);
		}
	}
}