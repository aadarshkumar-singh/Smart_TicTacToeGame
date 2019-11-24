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

CComputerPlayer::~CComputerPlayer()
{
	// TODO Auto-generated destructor stub
}

void CComputerPlayer::placeTile(BoardState_t tileinfo, BoardState_t **board)
{
	findBestMove(tileinfo,board);
	if(board[m_bestRow][m_bestColumn] == EMPTY)
	{
		board[m_bestRow][m_bestColumn] = tileinfo;
	}
	else
	{
		cout<<"Invalid"<<endl;
	}
}

void CComputerPlayer::findBestMove(BoardState_t playerTile, BoardState_t **board)
{
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (checkIfEmpty(board) == 1)
	{
		m_bestRow =1;
		m_bestColumn =1;
	}
	else if (checkIfAttackOrBlock(playerTile,board) == 1)
	{
		//Do nothing
	}
	else if (checkIfAttackOrBlock(opponentTile,board) == 1)
	{
		// Do nothing
	}
	else if(checkIfOpponentisInCorner(playerTile,board) == 1)
	{
		// Do nothing
	}
	else if(checkIfCornerOrSideEmpty(playerTile,board,CORNER) == 1)
	{
		//Do nothing
	}
	else if(checkIfCornerOrSideEmpty(playerTile,board,SIDE) == 1)
	{
		//Do nothing
	}
}


int CComputerPlayer::checkIfAttackOrBlock(BoardState_t playerTile,BoardState_t **board)
{
	int size ;
	size = m_boardSize.getBoardRowSize();
	int result = 0;

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (board[rowIndex][columnIndex] == EMPTY )
			{
				board[rowIndex][columnIndex] = playerTile ;
				if (checkIfWon(playerTile,board) == 1)
				{
					m_bestRow = rowIndex ;
					m_bestColumn =columnIndex;
					result = 1 ;
				}
				board[rowIndex][columnIndex] = EMPTY ;
			}
		}
	}

	return result;
}

int CComputerPlayer::checkIfOpponentisInCorner(BoardState_t playerTile,
		BoardState_t **board)
{
	int result = 0;
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (board[0][0] == opponentTile)
	{
		if (board[2][2] == EMPTY)
		{
			m_bestRow = 2;
			m_bestColumn =2;
			result =1 ;
		}

	}
	else if(board[0][2] == opponentTile)
	{
		if (board[2][0] == EMPTY)
		{
			m_bestRow = 2;
			m_bestColumn =0;
			result =1 ;
		}
	}
	else if(board[2][0] == opponentTile)
	{
		if(board[0][2] == EMPTY)
		{
			m_bestRow = 0;
			m_bestColumn =2;
			result =1 ;
		}
	}
	else if (board[2][2] == opponentTile)
	{
		if(board[0][0] == EMPTY)
		{
			m_bestRow = 0;
			m_bestColumn =0;
			result =1 ;
		}
	}

	return result;
}
int CComputerPlayer::checkIfCornerOrSideEmpty(BoardState_t playerTile,BoardState_t **board, playerMoves_t checkMove)
{
	int result =0 ;
	int size;
	size =m_boardSize.getBoardRowSize();

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (checkMove == CORNER)
			{
				if ((rowIndex % 2 )== 0 && (columnIndex % 2 ==0))
				{
					if (board[rowIndex][columnIndex] == EMPTY)
					{
						m_bestRow = rowIndex ;
						m_bestColumn = columnIndex ;
						result = 1 ;
						break;
					}
				}

			}
			else if (checkMove == SIDE)
			{
				if (board[1][1] == EMPTY)
				{
					m_bestRow = 1 ;
					m_bestColumn = 1 ;
					result = 1 ;
					break;
				}
				else if (((rowIndex + columnIndex) % 2) == 1)
				{
					if (board[rowIndex][columnIndex] == EMPTY)
					{
						m_bestRow = rowIndex ;
						m_bestColumn = columnIndex ;
						result = 1 ;
						break;
					}
				}

			}

		}
		if (result == 1)
		{
			break;
		}
	}


	return result;
}

int CComputerPlayer::checkIfWon(BoardState_t playerTile,BoardState_t **board)
{
	int winStatus = 0 ;

	if (checkRowsOrColumnForWin(playerTile,board) == 1)
	{
		winStatus =1;
	}
	else if(checkDiagnolsForWin(playerTile,board)==1)
	{
		winStatus = 1;
	}

	return winStatus;
}

int CComputerPlayer::checkIfEmpty(BoardState_t **board)
{
	int results = 0 ;
	int size;
	int flag =0 ;
	size =m_boardSize.getBoardRowSize();

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (board[rowIndex][columnIndex] == EMPTY)
			{
				flag++ ;
			}
		}
	}

	if (flag == (size*size))
	{
		results = 1;
	}
	return results;
}
int CComputerPlayer::checkRowsOrColumnForWin(BoardState_t playerTile,
		BoardState_t **board)
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
			if (board [rowIndex][columnIndex] == playerTile)
			{
				++checkRowFlag ;
			}
			if (board [columnIndex][rowIndex] == playerTile)
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

int CComputerPlayer::checkDiagnolsForWin(BoardState_t playerTile,
		BoardState_t **board)
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
				if (board[rowIndex][columnIndex] == playerTile)
				{
					++checkPrimaryDiagnol ;
				}
			}

			if ((rowIndex + columnIndex) == (size -1))
			{
				if (board[rowIndex][columnIndex] == playerTile)
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
