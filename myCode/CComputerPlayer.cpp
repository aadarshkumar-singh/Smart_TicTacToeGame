/*
 * CComputerPlayer.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#include "CComputerPlayer.h"
#include "stdlib.h"

using namespace std;

CComputerPlayer::CComputerPlayer()
{
	// TODO Auto-generated constructor stub

}

CComputerPlayer::~CComputerPlayer()
{
	// TODO Auto-generated destructor stub
}

void CComputerPlayer::placeTile(BoardState_t tileinfo, BoardState_t **board)
{
	int rowPosition;
	int columnPosition;

	while(1)
	{
		rowPosition = rand() % 9;
		columnPosition = rand()%9;

		if(board[rowPosition][columnPosition] != EMPTY)
		{
			continue;
		}
		else
		{
			board[rowPosition][columnPosition] = tileinfo;
			break;
		}
	}
}
