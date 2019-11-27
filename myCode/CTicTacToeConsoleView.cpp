/***************************************************************************
****************************************************************************
 * \file CTicTacToeConsoleView.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeConsoleView.cpp
 *
 * Source file of the Class CTicTacToeConsoleView for displaying the board and
 * the result of the game in console View
 *
*************************************************************************/

#include "CTicTacToeConsoleView.h"
#include "iostream"

using namespace std;

/*
 * Initializes the instances with the address of the board, row size and the column size
 * respectively.
 *
 * @param ticTacToeBoardView : Pointer to store the address of the board
 * @param rowSize : row size of the board
 * @param columnSize : column size of the board
 */
CTicTacToeConsoleView::CTicTacToeConsoleView(BoardState_t **ticTacToeBoardView,
		int rowSize, int columnSize):CScreen(ticTacToeBoardView,rowSize,columnSize)
{

}
/*
 * prints the board on a console view screen
 */
void CTicTacToeConsoleView::printBoard()
{
	cout<<"\t \t0\t1\t2"<<endl;
	for (int rowIndex = 0; rowIndex < m_boardRowSize; rowIndex++)
	{
		cout<<"\t"<<rowIndex;
		for(int columnIndex =0 ;columnIndex < m_boardColumnSize;columnIndex++ )
		{
			cout <<"\t" <<static_cast<char>(m_pticTacToeBoardView[rowIndex][columnIndex]);
		}
		cout <<endl;
	}
}

CTicTacToeConsoleView::~CTicTacToeConsoleView()
{
	// Does nothing
}
/*
 * prints the result of the board game on a console view screen
 * @param Player : The player who has won
 * @param winTile: The tile that the winner player was playing with
 * @param result : If the game has resulted in a win/draw.
 */
void CTicTacToeConsoleView::printResult(gamePlayers_t Player, BoardState_t winTile,gameResult_t result)
{
	if (result == PLAYER_WON)
	{
		cout<<endl<<"Player "<<Player<<" With Tile :: "<<static_cast<char>(winTile) <<" Wins"<<endl;
	}
	else if (result == PLAYER_DRAW)
	{
		cout <<endl<<"Game Draw"<<endl;
	}
}
