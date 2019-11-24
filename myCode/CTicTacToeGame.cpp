/*
 * CTicTacToeGame.cpp
 *
 * Created on: Nov 18, 2019
 * Author: Aadarsh Kumar Singh
 *
 */

#include "CTicTacToeGame.h"
#include "iostream"

using namespace std;

CTicTacToeGame::CTicTacToeGame()
{
	m_ticTacToeBoard = new CTicTacToeBoard ;
}

void CTicTacToeGame::play()
{
	cout <<endl<<"----------------------------------------"<<endl;
	cout <<"Player 1 Plays with TILE X " <<endl;
	cout <<"Player 2 Plays with TILE O " <<endl;
	cout << "Lets play the TicTacToe game " <<endl;
	cout <<"----------------------------------------"<<endl;

	for (int rounds =0 ; rounds<MAXIMUM_POSIBLE_MOVES;rounds++)
	{
		m_ticTacToeBoard->displayBoard();
		cout <<endl <<"Placing a stone in round " << rounds+1 << endl;

		if (rounds%2)
		{
			m_ticTacToeBoard->getBoardPlayer2()->placeTile(TILE_O);
			if (checkGameResult(TILE_O) == PLAYER_WON)
			{
				m_ticTacToeBoard->displayResult(PLAYER2,TILE_O,PLAYER_WON);
				break;
			}

		}
		else
		{
			m_ticTacToeBoard->getBoardPlayer1()->placeTile(TILE_X);
			if (checkGameResult(TILE_X) == PLAYER_WON)
			{
				m_ticTacToeBoard->displayResult(PLAYER1,TILE_X,PLAYER_WON);
				break;
			}
		}
	}
	if (checkGameResult(TILE_X) == PLAYER_DRAW)
	{
		m_ticTacToeBoard->displayResult(PLAYER1,TILE_X,PLAYER_DRAW);
	}
}

gameResult_t CTicTacToeGame::checkGameResult(BoardState_t playerTile)
{
	gameResult_t result = PLAYER_PLAYING;
	int checkRowFlag = 0;
	int checkColumnFlag  =0 ;
	int checkPrimaryDiagnol = 0;
	int checkSecondaryDiagnol = 0 ;

	if (checkBoardFull() == PLAYER_DRAW)
	{
		result = PLAYER_DRAW;
	}

	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		checkRowFlag = 0;
		checkColumnFlag  =0;
		for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
		{
			if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
			{
				++checkRowFlag ;
			}

			if (m_ticTacToeBoard->getTicTacToeBoard()[columnIndex][rowIndex] == playerTile)
			{
				++checkColumnFlag ;
			}

			if (rowIndex == columnIndex)
			{
				if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
				{
					++checkPrimaryDiagnol ;
				}
			}

			if ((rowIndex + columnIndex) == (TICTACTOE_ROW_SIZE -1))
			{
				if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
				{
					++checkSecondaryDiagnol ;
				}
			}
		}
		if (checkRowFlag == TICTACTOE_ROW_SIZE || checkColumnFlag == TICTACTOE_COLUMN_SIZE)
		{
			result = PLAYER_WON;;
			break;
		}
	}
	if (checkPrimaryDiagnol == TICTACTOE_ROW_SIZE || checkSecondaryDiagnol == TICTACTOE_ROW_SIZE)
	{
		result = PLAYER_WON;;
	}

	return result;
}

gameResult_t CTicTacToeGame::checkBoardFull()
{
	gameResult_t results = PLAYER_DRAW ;

	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
		{
			if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == EMPTY)
			{
				results = PLAYER_PLAYING ;
				break;
			}
		}
	}

	return results;
}

CTicTacToeGame::~CTicTacToeGame()
{
	// TODO Auto-generated destructor stub
}
