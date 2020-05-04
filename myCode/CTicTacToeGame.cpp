/***************************************************************************
****************************************************************************
 * \file CTicTacToeGame.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeGame.cpp
 * Source file for the class CTicTacToeGame. The Logic to play the
 * tictactoe game is implemented in this class.
 *
****************************************************************************/

#include "CTicTacToeGame.h"
#include "iostream"

using namespace std;

/*
 * initializes the pointer m_ticTacToeBoard to store the address of tictactoe board
 * created
 */
CTicTacToeGame::CTicTacToeGame()
{
	m_ticTacToeBoard = new CTicTacToeBoard ;
}

/*
 * There are maximum of 9 moves, each player take turns.
 * Player 1 goes first followed by player 2 and
 * if the player has won or game is draw the result is displayed on the screen.
 */
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
			/*Get Move of player 2*/
			m_ticTacToeBoard->getBoardPlayer2()->placeTile(TILE_O);
			if (checkGameResult(TILE_O) == PLAYER_WON)
			{
				m_ticTacToeBoard->displayResult(PLAYER2,TILE_O,PLAYER_WON);
				break;
			}

		}
		else
		{
			/*Get move of player 1*/
			m_ticTacToeBoard->getBoardPlayer1()->placeTile(TILE_X);
			if (checkGameResult(TILE_X) == PLAYER_WON)
			{
				m_ticTacToeBoard->displayResult(PLAYER1,TILE_X,PLAYER_WON);
				break;
			}
		}
	}
	/*Check if the Game is draw */
	if (checkGameResult(TILE_X) == PLAYER_DRAW)
	{
		m_ticTacToeBoard->displayResult(PLAYER1,TILE_X,PLAYER_DRAW);
	}
}

/*
 * Checks the Result if a player with tile has won,
 * Checks each row, column, primary and secondary diagnol
 * if all 3 are found of the same tile then we say Player has won,
 * if board is full game is draw or the game is in progress
 */
gameResult_t CTicTacToeGame::checkGameResult(BoardState_t playerTile)
{
	gameResult_t result = PLAYER_PLAYING;
	int checkRowFlag = 0;
	int checkColumnFlag  =0 ;
	int checkPrimaryDiagnol = 0;
	int checkSecondaryDiagnol = 0 ;

	/*Check for draw , if board is full*/
	if (checkBoardFull() == PLAYER_DRAW)
	{
		result = PLAYER_DRAW;
	}
	/*Check if possibly player has won*/
	for (int rowIndex = 0; rowIndex<TICTACTOE_ROW_SIZE ; rowIndex++)
	{
		checkRowFlag = 0;
		checkColumnFlag  =0;
		for (int columnIndex = 0; columnIndex<TICTACTOE_COLUMN_SIZE ; columnIndex++)
		{
			/*Check Each row for 3 similar tiles*/
			if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
			{
				++checkRowFlag ;
			}
			/*Check Each column for 3 similar tiles*/
			if (m_ticTacToeBoard->getTicTacToeBoard()[columnIndex][rowIndex] == playerTile)
			{
				++checkColumnFlag ;
			}
			/*Check primary diagnol for 3 similar tiles*/
			if (rowIndex == columnIndex)
			{
				if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
				{
					++checkPrimaryDiagnol ;
				}
			}
			/*Check secondary diagnol for 3 similar tiles*/
			if ((rowIndex + columnIndex) == (TICTACTOE_ROW_SIZE -1))
			{
				if (m_ticTacToeBoard->getTicTacToeBoard()[rowIndex][columnIndex] == playerTile)
				{
					++checkSecondaryDiagnol ;
				}
			}
		}
		/*Check if 3 similar tiles are present in a single row/Column */
		if (checkRowFlag == TICTACTOE_ROW_SIZE || checkColumnFlag == TICTACTOE_COLUMN_SIZE)
		{
			result = PLAYER_WON;;
			break;
		}
	}
	/*Check if 3 similar tiles are present in a primary/secondary diagnol */
	if (checkPrimaryDiagnol == TICTACTOE_ROW_SIZE || checkSecondaryDiagnol == TICTACTOE_ROW_SIZE)
	{
		result = PLAYER_WON;;
	}

	return result;
}

/*Check if Board is full, if full return PLAYER_DRAW else return PLAYER_PLAYING */
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

/*
 * Frees the memory of the m_ticTacToeBoard pointer that points to the tictactoe board
 */
CTicTacToeGame::~CTicTacToeGame()
{
	// TODO Auto-generated destructor stub
	delete[] m_ticTacToeBoard;
}
