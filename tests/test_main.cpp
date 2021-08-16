/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <antoine@mineau.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:30:33 by amineau           #+#    #+#             */
/*   Updated: 2021/08/01 15:43:06 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "Game/Chess.hpp"
#include "catch.hpp"

TEST_CASE("Move representation")
{
	Chess chess = Chess();
	Move* move;

	SECTION("Pawn move")
	{
		SECTION("Simple white Move")
		{
			chess.load("k7/8/8/8/8/P7/8/4K3 w - - 0 1");
			move = chess.getMoveAction("a3", "a4");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("a4") == 0);
		}
		SECTION("Simple black Move")
		{
			chess.load("k7/8/p7/8/8/8/8/4K3 b - - 0 1");
			move = chess.getMoveAction("a6", "a5");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("a5") == 0);
		}
		SECTION("Double push Move")
		{
			chess.load("k7/8/8/8/8/8/P7/4K3 w - - 0 1");
			move = chess.getMoveAction("a2", "a4");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("a4") == 0);
		}
		SECTION("Capture Move")
		{
			chess.load("k7/8/p7/1P6/8/8/8/4K3 w - - 0 1");
			move = chess.getMoveAction("b5", "a6");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("bxa6") == 0);
		}
		SECTION("Capture En Passant Move")
		{
			chess.load("k7/8/8/pP6/8/8/8/4K3 w - a6 0 1");
			move = chess.getMoveAction("b5", "a6");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("bxa6e.p") == 0);
		}
	}
	SECTION("Castling move")
	{
		SECTION("King Side")
		{
			chess.load("k7/8/8/8/8/8/8/4K2R w K - 0 1");
			move = chess.getMoveAction("e1", "g1");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("O-O") == 0);
		}
		SECTION("Queen Side")
		{
			chess.load("k7/8/8/8/8/8/8/R3K3 w Q - 0 1");
			move = chess.getMoveAction("e1", "c1");
			REQUIRE(chess.makeAction(move));
			REQUIRE(move->getRepr().compare("O-O-O") == 0);
		}
	}
}

TEST_CASE("Invalid moves")
{
	Chess chess = Chess();
	Move* move;

	SECTION("Capture")
	{

		SECTION("Self color")
		{
			chess.load("k7/pppppppp/8/N7/1B6/8/PPPPPPPP/4K3 w - - 0 1");
			move = chess.getMoveAction("b4", "a5");

			REQUIRE(chess.getPiece("b4")->getType() == BISHOP);
			REQUIRE(chess.getPiece("b4")->isWhite() == true);
			REQUIRE(chess.getPiece("a5")->getType() == KNIGHT);
			REQUIRE(chess.getPiece("a5")->isWhite() == true);
			REQUIRE(move->isLegal() == 0);
		}
		SECTION("Cause self check")
		{
			Spot*					 queen;
			std::vector<std::string> list_spots;

			chess.load("k1r5/2Q5/8/2K5/8/8/8/8 w - - 0 1");
			queen = chess.getSpot("c7");
			for (auto spot : chess.validSpots(queen))
				list_spots.push_back(spot->getRepr());
			REQUIRE(list_spots == std::vector<std::string>({
						"c6",
						"c8",
						}));
		}
	}
}

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
		SECTION("Pawn prise en passant")
		{
			Piece* pawn;
			chess.load("8/8/8/8/Pp6/8/8/2k1K3 b - a3 0 1");

			pawn = chess.getPiece("b4");
			REQUIRE(pawn->getType() == PAWN);
			REQUIRE(pawn->isWhite() == false);

			move = chess.getMoveAction("b4", "a3");

			REQUIRE(chess.makeAction(move) == true);
			REQUIRE(chess.getPiece("a3") == pawn);
			REQUIRE(chess.getPiece("a3")->isWhite() == false);
			REQUIRE(chess.getPiece("a4") == nullptr);
			REQUIRE(chess.getWhiteSpots().size() == 1);
		}
	}
}

TEST_CASE("Status")
{
	Chess chess = Chess();
	Move* move;

	SECTION("INPROGRESS")
	{
		chess.load("k7/8/8/8/8/8/P7/K7 w - - 0 1");
		move = chess.getMoveAction("a2", "a4");
		REQUIRE(chess.makeAction(move));
		REQUIRE(chess.getStatus() == INPROGRESS);
	}
	SECTION("CHECKMATE")
	{
		chess.load("k7/1R6/1Q6/8/8/8/8/4K3 w - - 0 1");
		move = chess.getMoveAction("b6", "a7");
		REQUIRE(chess.makeAction(move));
		REQUIRE(chess.getStatus() == CHECKMATE);
	}
	SECTION("STALEMATE")
	{
		chess.load("k7/8/8/8/8/8/8/3RK3 w - - 49 1");
		move = chess.getMoveAction("d1", "c1");
		REQUIRE(chess.makeAction(move));
		REQUIRE(chess.getStatus() == STALEMATE);
	}
	SECTION("DRAW")
	{
		chess.load("k1K5/1R6/8/8/8/8/8/8 w - - 0 1");
		move = chess.getMoveAction("b7", "c7");
		REQUIRE(chess.makeAction(move));
		REQUIRE(chess.getStatus() == DRAW);
	}

	SECTION("TREEFOLDREPETITION")
	{
		/** NOT IMPLEMENTED FEATURE **/
	}
	SECTION("INSUFFICIENTMATERIAL")
	{
		/** NOT IMPLEMENTED FEATURE **/

		//SECTION("KING vs KING")
		//{
		//    chess.load("k1K5/R7/8/8/8/8/8/8 b - - 0 1");
		//    move = chess.getMoveAction("a8", "a7");
		//    REQUIRE(chess.makeAction(move));
		//    REQUIRE(chess.getStatus() == INSUFFICIENTMATERIAL);
		//}
		//SECTION("KING vs KING with KNIGHT")
		//{
		//    chess.load("k1K5/R7/8/8/8/8/8/N7 b - - 0 1");
		//    move = chess.getMoveAction("a8", "a7");
		//    REQUIRE(chess.makeAction(move));
		//    REQUIRE(chess.getStatus() == INSUFFICIENTMATERIAL);
		//}
		//SECTION("KING vs KING with BISHOP")
		//{
		//    chess.load("k1K5/R7/8/8/8/8/8/B7 b - - 0 1");
		//    move = chess.getMoveAction("a8", "a7");
		//    REQUIRE(chess.makeAction(move));
		//    REQUIRE(chess.getStatus() == INSUFFICIENTMATERIAL);
		//}

	}

}

TEST_CASE("End game")
{
	Chess chess = Chess();
	Move* move;

	SECTION("Denied actions")
	{
		chess.load("k7/8/8/8/8/8/8/3RK3 b - - 50 1");
		move = chess.getMoveAction("a8", "a7");
		REQUIRE(chess.getStatus() == STALEMATE);
		REQUIRE(move->isLegal() == true);
		REQUIRE(chess.makeAction(move) == false);
	}
}
