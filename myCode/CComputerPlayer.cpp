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

void CComputerPlayer::findBestMove(BoardState_t tileinfo, BoardState_t **board)
{

	if (checkIfEmpty(board) == 1)
	{
		m_bestRow =1;
		m_bestColumn =1;
	}
	else if (checkIfAttack(tileinfo,board) == 1)
	{
		//Do nothing
	}
	else if (checkIfBlock(tileinfo,board) == 1)
	{
		// Do nothing
	}
	else if(checkIfOpponentisInCorner(tileinfo,board) == 1)
	{
		// Do nothing
	}
	else if(checkIfCornerEmpty(tileinfo,board) == 1)
	{
		//Do nothing
	}
	else if(checkifSidesEmpty(tileinfo,board) == 1)
	{
		//Do nothing
	}
}


int CComputerPlayer::checkifSidesEmpty(BoardState_t playerTile,
		BoardState_t **board)
{
	int result =1;

	if (board[1][1] == EMPTY)
	{
		m_bestRow = 1;
		m_bestColumn = 1;
	}
	else if (board[0][1] == EMPTY)
	{
		m_bestRow = 0;
		m_bestColumn = 1;
	}
	else if (board[1][0] == EMPTY)
	{
		m_bestRow = 1;
		m_bestColumn = 0;
	}
	else if (board[1][2] == EMPTY)
	{
		m_bestRow = 1;
		m_bestColumn = 2;
	}
	else if (board[2][1] == EMPTY)
	{
		m_bestRow = 2;
		m_bestColumn = 1;
	}
	else
	{
		result = 0;
	}

	return result;
}

int CComputerPlayer::checkIfAttack(BoardState_t playerTile,BoardState_t **board)
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

int CComputerPlayer::checkIfBlock(BoardState_t playerTile, BoardState_t **board)
{
	int size ;
	size = m_boardSize.getBoardRowSize();
	int result = 0;

	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (board[rowIndex][columnIndex] == EMPTY )
			{
				board[rowIndex][columnIndex] = opponentTile ;
				if (checkIfWon(opponentTile,board) == 1)
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
int CComputerPlayer::checkIfCornerEmpty(BoardState_t playerTile,
		BoardState_t **board)
{
	int result =0 ;
	if (board[0][0] == EMPTY)
	{
		m_bestRow = 0;
		m_bestColumn =0;
		result =1 ;
	}
	else if(board[0][2] == EMPTY)
	{
		m_bestRow = 0;
		m_bestColumn =2;
		result =1 ;
	}
	else if(board[2][0] == EMPTY)
	{
		m_bestRow = 2;
		m_bestColumn =0;
		result =1 ;
	}
	else if (board[2][2] == EMPTY)
	{
		m_bestRow = 2;
		m_bestColumn =2;
		result =1 ;
	}

	return result;
}

int CComputerPlayer::checkIfWon(BoardState_t playerTile,BoardState_t **board)
{
	int winStatus = 0 ;

	if (checkRowsForWin(playerTile,board) == 1)
	{
		winStatus =1;
	}
	else if (checkColumnForWin(playerTile,board) == 1)
	{
		winStatus = 1;
	}
	else if(checkPrimaryDiagnolForWin(playerTile,board)==1)
	{
		winStatus = 1;
	}
	else if (checkSecondaryDiagnolForWin(playerTile,board) == 1)
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
int CComputerPlayer::checkRowsForWin(BoardState_t playerTile,
		BoardState_t **board)
{
	int results = 0 ;
	// Check row wins
	int checkFlag = 0;
	int size ;
	size = m_boardSize.getBoardRowSize();
	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		checkFlag = 0;
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if (board [rowIndex][columnIndex] == playerTile)
			{
				++checkFlag ;
			}
		}
		if (checkFlag == 3)
		{
			results = 1;
			break;
		}
	}
	return results;
}

int CComputerPlayer::checkColumnForWin(BoardState_t playerTile,
		BoardState_t **board)
{
	int checkFlag = 0;
	int results = 0;
	int size ;
	size = m_boardSize.getBoardRowSize();

	for (int columnIndex = 0; columnIndex<size ; columnIndex++)
	{
		checkFlag = 0;
		for (int rowIndex = 0; rowIndex< size; rowIndex++)
		{
			if (board[rowIndex][columnIndex] == playerTile)
			{
				++checkFlag ;
			}
		}
		if (checkFlag == size)
		{
			results = 1;
			break;
		}
	}
	return results;

}

int CComputerPlayer::checkPrimaryDiagnolForWin(BoardState_t playerTile,
		BoardState_t **board)
{
	int checkFlag = 0;
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
					++checkFlag ;
				}
			}
		}
	}
	if (checkFlag == size)
	{
		results = 1;
	}
	return results;

}

int CComputerPlayer::checkSecondaryDiagnolForWin(BoardState_t playerTile,
		BoardState_t **board)
{
	int checkFlag = 0;
	int results = 0;
	int size ;
	size = m_boardSize.getBoardRowSize();

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			if ((rowIndex + columnIndex) == (size -1))
			{
				if (board[rowIndex][columnIndex] == playerTile)
				{
					++checkFlag ;
				}
			}
		}
	}
	if (checkFlag == size)
	{
		results = 1;
	}
	return results;

}
