/***************************************************************************
****************************************************************************
 * \file CPosition.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CPosition.cpp
 * Source file for the CPosition class that sets the board dimension as specified,
 * if the specified dimension is invalid it returns error.
 * It also gets the row and column position from player if he wants to
 * place the tile on the board, if the position given by the player is
 * out of board , it asks to give input again.
 *
*************************************************************************/

#include "CPosition.h"
#include "iostream"

using namespace std;

/*
 * Static Row size is declared global as Static Data Members have file scope
 */
int CPosition::m_rowCount;

/*
 * Static Column size is declared global as Static Data Members have file scope
 */
int CPosition::m_columnCount;

/*
 * Default Constructor to initialize the row and column Position
 * that the player will set for the move to be Zero
 */
CPosition::CPosition()
{
	m_rowPosition = 0;
	m_columnPosition = 0;
}

/*
 * Returns the row Position specified by the player
 */
int CPosition::getRowPosition()
{
	return (m_rowPosition);
}

/*
 * Returns the column Position specified by the player
 */
int CPosition::getColumnPosition()
{
	return(m_columnPosition);
}

/*
 * Sets the Board Dimension, if invalid row and column count
 * returns error
 */
PositionErrorCode_t CPosition::setBoardDimension(int rowCount , int columnCount)
{
	PositionErrorCode_t errCode = VALID_SIZE;

	if (rowCount <= 0)
	{
		errCode = INVALID_ROW_SIZE ;
	}
	else if (columnCount <= 0)
	{
		errCode = INVALID_COLUMN_SIZE ;
	}
	else
	{
		m_rowCount = rowCount;
		m_columnCount =columnCount;
	}

	return errCode;
}

/*
 * Gets the row and the column position for the move on the board from the player
 * If player enters position out of board dimension throws an error and asks the
 * player to enter the position again
 */
void CPosition::getMoveFromPlayer()
{
	while(1)
	{
		cout<<"Enter move row column ::> "<<endl;
		cin>>m_rowPosition>>m_columnPosition;

		if (m_rowPosition < 0 || m_rowPosition >= m_rowCount || m_columnPosition < 0 || m_columnPosition >= m_columnCount)
		{
			cout <<"Invalid Move, Enter again "<<endl;
		}
		else
		{
			break;
		}
	}
}

/*
 * Returns the Row size of the Board
 */
int CPosition::getBoardRowSize()
{
	return (m_rowCount);
}

/*
 * Returns the Column size of the Board
 */
int CPosition::getBoardColumnSize()
{
	return(m_columnCount);
}
