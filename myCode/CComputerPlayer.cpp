/*
 * CComputerPlayer.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#include "CComputerPlayer.h"
#include <stdlib.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

CComputerPlayer::CComputerPlayer()
{
	// TODO Auto-generated constructor stub
	m_playerBoard = NULL;
	m_bestColumn = 0;
	m_bestRow = 0;

}

CComputerPlayer::CComputerPlayer(BoardState_t **pboard)
{
	m_playerBoard = pboard;
	m_bestColumn = 0;
	m_bestRow = 0;
}

CComputerPlayer::~CComputerPlayer()
{
	int size = m_boardSize.getBoardRowSize();
    for (int rowIndex = 0 ; rowIndex < size ; rowIndex++)
    {
    	delete[] m_playerBoard[rowIndex]; // clean up already allocated rows
    }

    delete[] m_playerBoard;
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

	if (checkToAttackBlockOrPlace(playerTile,MOVE_EMPTY_BOARD) == AVAILABLE)
	{
		// Do nothing
	}
	else if (checkToAttackBlockOrPlace(playerTile,MOVE_ATTACKORBLOCK) == AVAILABLE)
	{
		//Do nothing
	}
	else if (checkToAttackBlockOrPlace(opponentTile,MOVE_ATTACKORBLOCK) == AVAILABLE)
	{
		// Do nothing
	}
	else if (blockFork(playerTile))
	{
		// Do nothing
	}
	else if(checkToAttackBlockOrPlace(playerTile,MOVE_CORNER) == AVAILABLE)
	{
		//Do nothing
	}
	else if(checkToAttackBlockOrPlace(playerTile,MOVE_EDGE) == AVAILABLE)
	{
		//Do nothing
	}
}

moveAvailablity_t CComputerPlayer::blockFork(BoardState_t playerTile)
{
	moveAvailablity_t result =UNAVAILABLE ;
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (m_playerBoard[1][1] == playerTile)
	{
		if ((m_playerBoard[0][0] == opponentTile) && (m_playerBoard[2][2] == opponentTile))
		{
			result = checkToAttackBlockOrPlace(playerTile,MOVE_EDGE);
		}
		else if((m_playerBoard[0][2] == opponentTile) && (m_playerBoard[2][0] == opponentTile))
		{
			result = checkToAttackBlockOrPlace(playerTile,MOVE_EDGE);
		}
		else if((m_playerBoard[1][2] == opponentTile) && (m_playerBoard[2][1] == opponentTile))
		{
			if(m_playerBoard[2][2] == EMPTY)
			{
				m_bestRow = 2;
				m_bestColumn =2;
				result = AVAILABLE;
			}
		}
	}
	else if(m_playerBoard[1][1] == EMPTY)
	{
		m_bestRow = 1 ;
		m_bestColumn = 1 ;
		result = AVAILABLE;
	}
	return result;
}

moveAvailablity_t CComputerPlayer::checkToAttackBlockOrPlace(BoardState_t playerTile, playerMoves_t checkMove)
{
	moveAvailablity_t result =UNAVAILABLE ;
	int size = m_boardSize.getBoardRowSize();
	int randomInitialVal =0 ;
	int checkBoardEmpty= 0;
	int initialPossibleMove[5][2] = {{1,1},{0, 0}, {0, 2}, {2, 0}, {2, 2}};

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (checkMove == MOVE_CORNER)
			{
				if ((rowIndex % 2 )== 0 && (columnIndex % 2 ==0))
				{
					if (m_playerBoard[rowIndex][columnIndex] == EMPTY)
					{
						m_bestRow = rowIndex ;
						m_bestColumn = columnIndex ;
						result = AVAILABLE ;
						break;
					}
				}

			}
			else if (checkMove == MOVE_EDGE)
			{
				if (((rowIndex + columnIndex) % 2) == 1)
				{
					if (m_playerBoard[rowIndex][columnIndex] == EMPTY)
					{
						m_bestRow = rowIndex ;
						m_bestColumn = columnIndex ;
						result = AVAILABLE ;
						break;
					}
				}

			}
			else if (checkMove == MOVE_ATTACKORBLOCK)
			{
				if (m_playerBoard[rowIndex][columnIndex] == EMPTY )
				{
					m_playerBoard[rowIndex][columnIndex] = playerTile ;
					if (checkIfWon(playerTile) == IS_WINNING_MOVE)
					{
						m_bestRow = rowIndex ;
						m_bestColumn =columnIndex;
						result = AVAILABLE ;
					}
					m_playerBoard[rowIndex][columnIndex] = EMPTY ;
				}
			}
			else if (checkMove == MOVE_EMPTY_BOARD)
			{
				if (m_playerBoard[rowIndex][columnIndex] == EMPTY)
				{
					checkBoardEmpty++ ;
				}
			}
		}
		if (result == AVAILABLE)
		{
			break;
		}
	}
	if (checkBoardEmpty == (size*size))
	{
		randomInitialVal = rand () % 5;
		m_bestRow = initialPossibleMove[randomInitialVal][0];
		m_bestColumn = initialPossibleMove[randomInitialVal][1];
		result =AVAILABLE;
	}
	return result;
}

moveAvailablity_t CComputerPlayer::checkIfWon(BoardState_t playerTile)
{
	moveAvailablity_t results = NOT_A_WINNING_MOVE ;
	// Check row wins
	int checkRowFlag = 0;
	int checkColumnFlag  =0 ;
	int checkPrimaryDiagnol = 0;
	int checkSecondaryDiagnol = 0 ;
	int size = m_boardSize.getBoardRowSize();
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
		if (checkRowFlag == size || checkColumnFlag == size)
		{
			results = IS_WINNING_MOVE;
			break;
		}
	}
	if (checkPrimaryDiagnol == size || checkSecondaryDiagnol == size)
	{
		results = IS_WINNING_MOVE;
	}

	return results;
}
