/*
 * CHumanPlayer.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#include "CHumanPlayer.h"
#include "iostream"

using namespace std;

CHumanPlayer::CHumanPlayer(BoardState_t **playerboard)
{
	// TODO Auto-generated constructor stub
	m_playerboard =playerboard;

}

CHumanPlayer::~CHumanPlayer()
{
	int size = m_playerPosition.getBoardRowSize();
    for (int rowIndex = 0 ; rowIndex < size ; rowIndex++)
    {
    	delete[] m_playerboard[rowIndex]; // clean up already allocated rows
    }

    delete[] m_playerboard;
}

void CHumanPlayer::placeTile(BoardState_t tileinfo)
{
	int rowPosition;
	int columnPosition;

	while(1)
	{
		m_playerPosition.getMoveFromPlayer();
		rowPosition = m_playerPosition.getRowPosition();
		columnPosition = m_playerPosition.getColumnPosition();

		if (m_playerboard[rowPosition][columnPosition] != EMPTY)
		{
			cout <<"Invalid :: Tile is Already placed, Enter Again"<<endl;
		}
		else
		{
			m_playerboard[rowPosition][columnPosition]=tileinfo;
			break;
		}
	}
}
