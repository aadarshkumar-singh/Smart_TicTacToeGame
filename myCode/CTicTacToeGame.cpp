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
	cout <<"Player 1 Plays with TILE X " <<endl;
	cout <<"Player 2 Plays with TILE O " <<endl;
	cout << "Lets start the TicTacToe game " <<endl;

	for (int rounds =0 ; rounds<MAXIMUM_POSIBLE_MOVES;rounds++)
	{
		m_ticTacToeBoard->displayBoard();
		cout <<endl <<"Placing a stone in round " << rounds+1 << endl;
		if (rounds%2)
		{
			m_ticTacToeBoard->getBoardPlayer2()->placeTile(TILE_O,m_ticTacToeBoard->getTicTacToeBoard());
			if (checkGameResult(TILE_O) == PLAYER_WON)
			{
				m_ticTacToeBoard->displayResult(PLAYER2,TILE_O);
				break;
			}

		}
		else
		{
			m_ticTacToeBoard->getBoardPlayer1()->placeTile(TILE_X,m_ticTacToeBoard->getTicTacToeBoard());
			if (checkGameResult(TILE_X) == PLAYER_WON)
			{
				m_ticTacToeBoard->displayResult(PLAYER1,TILE_X);
				break;
			}
		}
	}
}

gameResult_t CTicTacToeGame::checkGameResult(BoardState_t playerTile)
{
	gameResult_t result = PLAYER_LOST;

	if ((checkRowForResult(playerTile)) == PLAYER_WON)
	{
		result = PLAYER_WON ;
	}
	else if ((checkColumnForResult(playerTile)) == PLAYER_WON)
	{
		result = PLAYER_WON ;
	}
	else if ((checkPrimaryDiagnolForResult(playerTile) == PLAYER_WON))
	{
		result = PLAYER_WON;
	}
	else if ((checkSecondaryDiagnolForResult(playerTile) == PLAYER_WON))
	{
		result = PLAYER_WON;
	}
	return result;
}

gameResult_t CTicTacToeGame::checkRowForResult(BoardState_t playerTile)
{
	int score = 0;
	gameResult_t results =PLAYER_LOST;

	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		score = 0;

		for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
		{
			if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
			{
				++score ;
			}
		}
		if (score == TICTACTOE_ROW_SIZE)
		{
			results = PLAYER_WON;
			break;
		}
	}
	return results;
}

gameResult_t CTicTacToeGame::checkColumnForResult(BoardState_t playerTile)
{
	int score = 0;
	gameResult_t results = PLAYER_LOST;

	for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
	{
		score = 0;
		for (int rowIndex = 0; rowIndex< TICTACTOE_ROW_SIZE; rowIndex++)
		{
			if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
			{
				++score ;
			}
		}
		if (score == TICTACTOE_COLUMN_SIZE)
		{
			results = PLAYER_WON;
			break;
		}
	}
	return results;
}

gameResult_t CTicTacToeGame::checkPrimaryDiagnolForResult(BoardState_t playerTile)
{
	int score = 0;
	gameResult_t results = PLAYER_LOST;

	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
		{
			if (rowIndex == columnIndex)
			{
				if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
				{
					++score ;
				}
			}
		}
	}
	if (score == TICTACTOE_ROW_SIZE)
	{
		results = PLAYER_WON;
	}
	return results;
}

gameResult_t CTicTacToeGame::checkSecondaryDiagnolForResult(BoardState_t playerTile)
{
	int score = 0;
	gameResult_t results = PLAYER_LOST;

	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
		{
			if ((rowIndex + columnIndex) == (TICTACTOE_ROW_SIZE -1))
			{
				if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
				{
					++score ;
				}
			}
		}
	}
	if (score == TICTACTOE_ROW_SIZE)
	{
		results = PLAYER_WON;
	}
	return results;

}

CTicTacToeGame::~CTicTacToeGame()
{
	// TODO Auto-generated destructor stub
}

