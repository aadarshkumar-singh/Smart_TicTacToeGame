/***************************************************************************
****************************************************************************
 * \file CComputerPlayer.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CComputerPlayer.cpp
 *
 * Source file for the class ComputerPlayer for the tictactoe board game,
 * This class defines the API to place the move of the computer player on the board.
 *
 * \note The computer decides to attack , defend or block fork as per the
 * 		 Opponents move. Computer may never lose.
*************************************************************************/

#include "CComputerPlayer.h"
#include <stdlib.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * Default constructor which initialises the m_playerBoard pointer to NULL
 * and best row and column to zero
 */
CComputerPlayer::CComputerPlayer()
{
	m_playerBoard = NULL;
	m_bestColumn = 0;
	m_bestRow = 0;

}

/*
 * Initializes the double Pointer m_playerBoard with the address
 *        of the TicTacToe board
 * pboard : Pointer to the TicTacToe board
 */
CComputerPlayer::CComputerPlayer(BoardState_t **pboard)
{
	m_playerBoard = pboard;
	m_bestColumn = 0;
	m_bestRow = 0;
}

void CComputerPlayer::placeTile(BoardState_t tileinfo)
{
	/*
	 * Decides the best possible row position for the computer player tile
	 */
	findBestMove(tileinfo);
	while(1)
	{
		/*
		 * Check if the the decided best possible position is empty
		 * if empty place the tile and break from infinite loop.
		 */
		if(m_playerBoard[m_bestRow][m_bestColumn] == EMPTY)
		{
			m_playerBoard[m_bestRow][m_bestColumn] = tileinfo;
			break;
		}
		else
		{
			/*
			 * If its not empty throw error message and find best move again
			 */
			cout<<"Invalid Move by Computer Error "<<endl;
			findBestMove(tileinfo);
		}

	}
}

/*
 * decides the best possible row and column based on the current
 * state of the board based on the below hierarchy :
 * -1.  empty board
 * -2.  computer can win in next move
 * -3.  needs to stop opponent from winning
 * -4.	block opponent fork
 * -5.  empty corner
 * -6.  empty side
 * tileinfo: Tile that the Computer player is going to place on the board.
 */
void CComputerPlayer::findBestMove(BoardState_t playerTile)
{

	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	if (checkToAttackBlockOrPlace(playerTile,MOVE_EMPTY_BOARD) == AVAILABLE)
	{
		/*
		 * Checks if board is empty , place in any of the
		 * POSSIBLE_INITIAL_WINING_MOVES available
		 */
	}
	else if (checkToAttackBlockOrPlace(playerTile,MOVE_ATTACKORBLOCK) == AVAILABLE)
	{
		/*
		 * Check if the computer player can win in the next move
		 * if AVAILABLE , Sets the row and column position
		 */
	}
	else if (checkToAttackBlockOrPlace(opponentTile,MOVE_ATTACKORBLOCK) == AVAILABLE)
	{
		/*
		 * Check if opponent can win in the next move
		 * if AVAILABLE, sets the row and column to block opponents winning move.
		 */
	}
	else if (blockFork(playerTile)== AVAILABLE)
	{
		/*
		 * Check if opponent trying to create fork for winning in the next move
		 * if AVAILABLE, sets the row and column to block opponents fork.
		 */
	}
	else if(checkToAttackBlockOrPlace(playerTile,MOVE_CORNER) == AVAILABLE)
	{
		/*
		 * Check if corner AVAILABLE , if available place in corner
		 */
	}
	else if(checkToAttackBlockOrPlace(playerTile,MOVE_EDGE) == AVAILABLE)
	{
		/*
		 * Check if edge AVAILABLE , if available place in edge
		 */
	}
}

moveAvailablity_t CComputerPlayer::blockFork(BoardState_t playerTile)
{
	moveAvailablity_t result =UNAVAILABLE ;
	BoardState_t opponentTile = (playerTile == TILE_X)?TILE_O:TILE_X ;

	/* Check if computer player is in center block forks */

	if (m_playerBoard[POSITION_ONE][POSITION_ONE] == playerTile)
	{
		/* Block Fork when opponents in opposite corner and player in center */

		/* Check in primary diagnol */
		if ((m_playerBoard[POSITION_ZERO][POSITION_ZERO] == opponentTile) &&
				(m_playerBoard[POSITION_TWO][POSITION_TWO] == opponentTile))
		{
			result = checkToAttackBlockOrPlace(playerTile,MOVE_EDGE);
		}

		/* Check in secondary diagnol */
		else if((m_playerBoard[POSITION_ZERO][POSITION_TWO] == opponentTile) &&
				(m_playerBoard[POSITION_TWO][POSITION_ZERO] == opponentTile))
		{
			result = checkToAttackBlockOrPlace(playerTile,MOVE_EDGE);
		}

		/* Block Side Fork*/
		else if((m_playerBoard[POSITION_ONE][POSITION_TWO] == opponentTile) &&
				(m_playerBoard[POSITION_TWO][POSITION_ONE] == opponentTile))
		{
			if(m_playerBoard[POSITION_TWO][POSITION_TWO] == EMPTY)
			{
				m_bestRow = POSITION_TWO;
				m_bestColumn =POSITION_TWO;
				result = AVAILABLE;
			}
		}
	}
	/* Check if center is empty , if empty fill center */
	else if(m_playerBoard[POSITION_ONE][POSITION_ONE] == EMPTY)
	{
		m_bestRow = POSITION_ONE ;
		m_bestColumn = POSITION_ONE ;
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

	/* The computer can play on center or corner initially to maximize win Probability*/
	int initialPossibleMove[5][2] = {{1,1},{0, 0}, {0, 2}, {2, 0}, {2, 2}};

	for (int rowIndex = 0; rowIndex<size ; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex<size ; columnIndex++)
		{
			/* Check if corner is free*/
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

			/* Check if edge is free*/
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

			/* Check next move is winning move, blocking move, or normal move */
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
			/* Check if first move is computer move  */
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
	/* if first move is computer move, randomly pick from all initial possible moves  */
	if (checkBoardEmpty == (size*size))
	{
		randomInitialVal = rand () % POSSIBLE_INITIAL_WINING_MOVES;
		m_bestRow = initialPossibleMove[randomInitialVal][POSITION_ZERO];
		m_bestColumn = initialPossibleMove[randomInitialVal][POSITION_ONE];
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
			/* Check Each Row  */
			if (m_playerBoard [rowIndex][columnIndex] == playerTile)
			{
				++checkRowFlag ;
			}

			/* Check Each Column */
			if (m_playerBoard [columnIndex][rowIndex] == playerTile)
			{
				++checkColumnFlag ;
			}

			/* Check Primary Diagnol */
			if (rowIndex == columnIndex)
			{
				if (m_playerBoard[rowIndex][columnIndex] == playerTile)
				{
					++checkPrimaryDiagnol ;
				}
			}
			/* Check Secondary Diagnol */
			if ((rowIndex + columnIndex) == (size -1))
			{
				if (m_playerBoard[rowIndex][columnIndex] == playerTile)
				{
					++checkSecondaryDiagnol ;
				}
			}
		}
		/* check if all elements in a row/column is of same tile */
		if (checkRowFlag == size || checkColumnFlag == size)
		{
			results = IS_WINNING_MOVE;
			break;
		}
	}
	/* if all elements in a primary/secondary diagnol is of same tile */
	if (checkPrimaryDiagnol == size || checkSecondaryDiagnol == size)
	{
		results = IS_WINNING_MOVE;
	}

	return results;
}

/*
 * frees the memory of the m_playerBoard data member that stores address
 * of the board.
 */
CComputerPlayer::~CComputerPlayer()
{
	int size = m_boardSize.getBoardRowSize();
	for (int rowIndex = 0 ; rowIndex < size ; rowIndex++)
	{
		delete[] m_playerBoard[rowIndex]; // clean up already allocated rows
	}

	delete[] m_playerBoard;
}
