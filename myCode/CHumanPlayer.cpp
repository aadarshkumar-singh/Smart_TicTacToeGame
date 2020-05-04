/***************************************************************************
****************************************************************************
 * \file CHumanPlayer.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CHumanPlayer.cpp
 *
 * Source file for the HumanPlayer Class  for the tictactoe board game,
 * This class defines the API to place the move of the human player on the board.
 *
 * \note If human makes invalid move , it asks the user again to enter the
 *       coordinates
*************************************************************************/

#include "CHumanPlayer.h"
#include "iostream"

using namespace std;

/*
 * Initializes the m_playerboard data member with the address
 * of the TicTacToe board
 */
CHumanPlayer::CHumanPlayer(BoardState_t **playerboard)
{
	m_playerboard =playerboard;
}

/*
 * Places the tile of the human player on the board
 * tileinfo : Tile that the Human player is going to place on the board.
 */
void CHumanPlayer::placeTile(BoardState_t tileinfo)
{
	int rowPosition = 0;
	int columnPosition= 0;

	while(1)
	{
		/* Get coordinate from human player*/
		m_playerPosition.getMoveFromPlayer();
		rowPosition = m_playerPosition.getRowPosition();
		columnPosition = m_playerPosition.getColumnPosition();

		if (m_playerboard[rowPosition][columnPosition] != EMPTY)
		{
			/*if entered invalid coordinate it asks to enter the coordinates again*/
			cout <<"Invalid :: Tile is Already placed, Enter Again"<<endl;
		}
		else
		{
			/* If valid place the tile and break from infinite loop */
			m_playerboard[rowPosition][columnPosition]=tileinfo;
			break;
		}
	}
}

/*
 * frees the memory of the m_playerboard data member that stores address
 * of the board.
 */
CHumanPlayer::~CHumanPlayer()
{
	int size = m_playerPosition.getBoardRowSize();
    for (int rowIndex = 0 ; rowIndex < size ; rowIndex++)
    {
    	delete[] m_playerboard[rowIndex]; // clean up already allocated rows
    }

    delete[] m_playerboard;
}
