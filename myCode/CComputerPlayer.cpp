/*
 * CComputerPlayer.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#include "CComputerPlayer.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

CComputerPlayer::CComputerPlayer()
{
	// TODO Auto-generated constructor stub


}

CComputerPlayer::CComputerPlayer(BoardState_t **pboard)
{
	m_playerBoard = pboard;
	m_bestColumn = 0;
	m_bestRow = 0;
}

CComputerPlayer::~CComputerPlayer()
{
	// TODO Auto-generated destructor stub
}

void CComputerPlayer::placeTile(BoardState_t tileinfo)
{
	findBestMove(tileinfo);
	if(m_playerBoard[m_bestRow][m_bestColumn] == EMPTY)
	{
		m_playerBoard[m_bestRow][m_bestColumn] = tileinfo;
	}
	else
	{
		cout<<"Invalid"<<endl;
	}
}

void CComputerPlayer::findBestMove(BoardState_t playerTile)
{
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (checkToAttackBlockOrPlace(playerTile,CENTER) == 1)
	{
		// Do nothing
	}
	else if (checkToAttackBlockOrPlace(playerTile,ATTACKORDEFEND) == 1)
	{
		//Do nothing
	}
	else if (checkToAttackBlockOrPlace(opponentTile,ATTACKORDEFEND) == 1)
	{
		// Do nothing
	}
	else if (blockFork(playerTile))
	{
		// Do nothing
	}
	else if(checkIfOpponentisInCorner(playerTile) == 1)
	{
		// Do nothing
	}
	else if(checkToAttackBlockOrPlace(playerTile,CORNER) == 1)
	{
		//Do nothing
	}
	else if(checkToAttackBlockOrPlace(playerTile,EDGE) == 1)
	{
		//Do nothing
	}
}

int CComputerPlayer::blockFork(BoardState_t playerTile)
{
	int result =0 ;
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (m_playerBoard[1][1] == playerTile)
	{
		if ((m_playerBoard[0][0] == opponentTile) && (m_playerBoard[2][2] == opponentTile))
		{
			result = checkToAttackBlockOrPlace(playerTile,EDGE);
		}
		else if((m_playerBoard[0][2] == opponentTile) && (m_playerBoard[2][0] == opponentTile))
		{
			result = checkToAttackBlockOrPlace(playerTile,EDGE);
		}
		else if((m_playerBoard[1][2] == opponentTile) && (m_playerBoard[2][1] == opponentTile))
		{
			if(m_playerBoard[2][2] == EMPTY)
			{
				m_bestRow = 2;
				m_bestColumn =2;
				result = 1;
			}
		}
	}
	else if(m_playerBoard[1][1] == EMPTY)
	{
		m_bestRow = 1 ;
		m_bestColumn = 1 ;
		result = 1;
	}


	return result;
}

int CComputerPlayer::checkIfOpponentisInCorner(BoardState_t playerTile)
{
	int result = 0;
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (m_playerBoard[0][0] == opponentTile)
	{
		if (m_playerBoard[2][2] == EMPTY)
		{
			m_bestRow = 2;
			m_bestColumn =2;
			result =1 ;
		}

	}
	else if(m_playerBoard[0][2] == opponentTile)
	{
		if (m_playerBoard[2][0] == EMPTY)
		{
			m_bestRow = 2;
			m_bestColumn =0;
			result =1 ;
		}
	}
	else if(m_playerBoard[2][0] == opponentTile)
	{
		if(m_playerBoard[0][2] == EMPTY)
		{
			m_bestRow = 0;
			m_bestColumn =2;
			result =1 ;
		}
	}
	else if (m_playerBoard[2][2] == opponentTile)
	{
		if(m_playerBoard[0][0] == EMPTY)
		{
			m_bestRow = 0;
			m_bestColumn =0;
			result =1 ;
		}
	}

	return result;
}
int CComputerPlayer::checkToAttackBlockOrPlace(BoardState_t playerTile, playerMoves_t checkMove)
{
	int result =0 ;
	int size;
	int checkCenterFree= 0;
	size =m_boardSize.getBoardRowSize();

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (checkMove == CORNER)
			{
				if ((rowIndex % 2 )== 0 && (columnIndex % 2 ==0))
				{
					if (m_playerBoard[rowIndex][columnIndex] == EMPTY)
					{
						m_bestRow = rowIndex ;
						m_bestColumn = columnIndex ;
						result = 1 ;
						break;
					}
				}

			}
			else if (checkMove == EDGE)
			{
				if (((rowIndex + columnIndex) % 2) == 1)
				{
					if (m_playerBoard[rowIndex][columnIndex] == EMPTY)
					{
						m_bestRow = rowIndex ;
						m_bestColumn = columnIndex ;
						result = 1 ;
						break;
					}
				}

			}
			else if (checkMove == ATTACKORDEFEND)
			{
				if (m_playerBoard[rowIndex][columnIndex] == EMPTY )
				{
					m_playerBoard[rowIndex][columnIndex] = playerTile ;
					if (checkIfWon(playerTile) == 1)
					{
						m_bestRow = rowIndex ;
						m_bestColumn =columnIndex;
						result = 1 ;
					}
					m_playerBoard[rowIndex][columnIndex] = EMPTY ;
				}
			}
			else if (checkMove == CENTER)
			{
				if (m_playerBoard[rowIndex][columnIndex] == EMPTY)
				{
					checkCenterFree++ ;
				}
			}
		}
		if (result == 1)
		{
			break;
		}
	}
	if (checkCenterFree == (size*size))
	{
		m_bestRow =1;
		m_bestColumn =1;
		result =1;
	}
	return result;
}

int CComputerPlayer::checkIfWon(BoardState_t playerTile)
{
	int winStatus = 0 ;

	if (checkRowsOrColumnForWin(playerTile) == 1)
	{
		winStatus =1;
	}
	else if(checkDiagnolsForWin(playerTile)==1)
	{
		winStatus = 1;
	}

	return winStatus;
}


int CComputerPlayer::checkRowsOrColumnForWin(BoardState_t playerTile)
{
	int results = 0 ;
	// Check row wins
	int checkRowFlag = 0;
	int checkColumnFlag  =0 ;
	int size ;
	size = m_boardSize.getBoardRowSize();
	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		checkRowFlag = 0;
		checkColumnFlag  =0;
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (m_playerBoard [rowIndex][columnIndex] == playerTile)
			{
				++checkRowFlag ;
			}
			if (m_playerBoard [columnIndex][rowIndex] == playerTile)
			{
				++checkColumnFlag ;
			}
		}
		if (checkRowFlag == 3 || checkColumnFlag == 3)
		{
			results = 1;
			break;
		}
	}
	return results;
}

int CComputerPlayer::checkDiagnolsForWin(BoardState_t playerTile)
{
	int checkPrimaryDiagnol = 0;
	int checkSecondaryDiagnol = 0 ;
	int results = 0;
	int size ;
	size = m_boardSize.getBoardRowSize();

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (rowIndex == columnIndex)
			{
				if (m_playerBoard[rowIndex][columnIndex] == playerTile)
				{
					++checkPrimaryDiagnol ;
				}
			}

			if ((rowIndex + columnIndex) == (size -1))
			{
				if (m_playerBoard[rowIndex][columnIndex] == playerTile)
				{
					++checkSecondaryDiagnol ;
				}
			}
		}
	}
	if (checkPrimaryDiagnol == size || checkSecondaryDiagnol == size)
	{
		results = 1;
	}
	return results;
}
