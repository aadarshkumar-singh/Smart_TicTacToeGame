/*
 * CTicTacToeConsoleView.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#include "CTicTacToeConsoleView.h"
#include "iostream"

using namespace std;

CTicTacToeConsoleView::CTicTacToeConsoleView(BoardState_t **ticTacToeBoardView):CScreen(ticTacToeBoardView)
{
	// TODO Auto-generated constructor stub

}

void CTicTacToeConsoleView::printScreen(int rowSize, int columnSize)
{
	int rowIndex =0;
	int columnIndex =0 ;
	cout<<"\t \t0\t1\t2"<<endl;
	for (rowIndex = 0; rowIndex < rowSize; rowIndex++)
	{
		cout<<"\t"<<rowIndex;
		for(columnIndex =0 ;columnIndex < columnSize;columnIndex++ )
		{
			cout <<"\t" <<static_cast<char>(m_ticTacToeBoardView[rowIndex][columnIndex]);
		}
		cout <<endl;
	}
}

CTicTacToeConsoleView::~CTicTacToeConsoleView()
{
	// TODO Auto-generated destructor stub
}

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
