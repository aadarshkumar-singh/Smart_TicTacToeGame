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

	/*
	 * Check Board Rows
	 */
	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		if ( m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][FIRST_COLUMN_INDEX] == playerTile &&
				m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][SECOND_COLUMN_INDEX] == playerTile &&
				m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][THIRD_COLUMN_INDEX] == playerTile)
		{
			result = PLAYER_WON;
		}
	}

	/*
	 * Check Board Columns
	 */
	for (int columnIndex = 0; columnIndex<TICTACTOE_ROW_SIZE ; columnIndex++)
	{
		if ( m_ticTacToeBoard->getTicTacToeBoard()[FIRST_ROW_INDEX][columnIndex] == playerTile &&
				m_ticTacToeBoard->getTicTacToeBoard()[SECOND_ROW_INDEX][columnIndex] == playerTile &&
				m_ticTacToeBoard->getTicTacToeBoard()[THIRD_ROW_INDEX][columnIndex] == playerTile)
		{
			result = PLAYER_WON;
		}
	}

	/*
	 * Check Primary Board Diagnol
	 */
	if (m_ticTacToeBoard->getTicTacToeBoard()[FIRST_ROW_INDEX][FIRST_COLUMN_INDEX] == playerTile &&
			m_ticTacToeBoard->getTicTacToeBoard()[SECOND_ROW_INDEX][SECOND_COLUMN_INDEX] == playerTile &&
			m_ticTacToeBoard->getTicTacToeBoard()[THIRD_ROW_INDEX][THIRD_COLUMN_INDEX] == playerTile)
	{
		result = PLAYER_WON;
	}

	/*
	 * Check secondary board Diagnol
	 */
	if (m_ticTacToeBoard->getTicTacToeBoard()[FIRST_ROW_INDEX][THIRD_COLUMN_INDEX] == playerTile &&
			m_ticTacToeBoard->getTicTacToeBoard()[SECOND_ROW_INDEX][SECOND_COLUMN_INDEX] == playerTile &&
			m_ticTacToeBoard->getTicTacToeBoard()[THIRD_ROW_INDEX][FIRST_COLUMN_INDEX] == playerTile)
	{
		result = PLAYER_WON;
	}

	return result;
}

CTicTacToeGame::~CTicTacToeGame()
{
	// TODO Auto-generated destructor stub
}

