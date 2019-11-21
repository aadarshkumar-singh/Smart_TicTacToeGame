/*
 * CTicTacToeGame.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: Aadarshxp
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
	cout << "Lets start the TicTacToe game ";
	m_ticTacToeBoard->displayBoard();
	for (int rounds =0 ; rounds<MAXIMUM_POSIBLE_MOVES;rounds++)
	{
		cout << "Placing a stone in round " << rounds+1 << endl;
		if (rounds%2)
		{
			m_ticTacToeBoard->getBoardPlayer2()->placeTile(TILE_O,m_ticTacToeBoard->getTicTacToeBoard());
			m_ticTacToeBoard->displayBoard();
		}
		else
		{
			m_ticTacToeBoard->getBoardPlayer1()->placeTile(TILE_X,m_ticTacToeBoard->getTicTacToeBoard());
			m_ticTacToeBoard->displayBoard();
		}
	}

}

CTicTacToeGame::~CTicTacToeGame()
{
	// TODO Auto-generated destructor stub
}

