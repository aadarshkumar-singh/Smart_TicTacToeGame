/*
 * CHumanPlayer.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#include "CHumanPlayer.h"
#include "iostream"

using namespace std;

CHumanPlayer::CHumanPlayer()
{
	// TODO Auto-generated constructor stub

}

CHumanPlayer::~CHumanPlayer()
{
	// TODO Auto-generated destructor stub
}

void CHumanPlayer::placeTile(BoardState_t tileinfo, BoardState_t **board)
{
	int rowPosition;
	int columnPosition;

	while(1)
	{
		m_playerPosition.getMoveFromPlayer();
		rowPosition = m_playerPosition.getRowPosition();
		columnPosition = m_playerPosition.getColumnPosition();

		if (board[rowPosition][columnPosition] != EMPTY)
		{
			cout <<"Invalid :: Tile is Already placed, Enter Again"<<endl;
		}
		else
		{
			board[rowPosition][columnPosition]=tileinfo;
			break;
		}
	}
}
