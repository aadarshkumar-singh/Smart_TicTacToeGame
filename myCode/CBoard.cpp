/***************************************************************************
****************************************************************************
 * \file CBoard.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CBoard.cpp
 *
 * Source file for the Class CBoard for creating and initializing a Generic board
 * for any Board game
 *
 * \note If the size of row and column to be set is invalid , then
 *  	 a 2D board with DEFAULT_BOARD_SIZE is created and initialized.
 *
****************************************************************************/

#include "CBoard.h"
#include "CPosition.h"
#include "iostream"

using namespace std;

CBoard::CBoard(int rowCount,int columnCount)
{
	PositionErrorCode_t errorCode;

	/*
    * Tries to set the board dimensions ,If the dimension is invalid
    * displays the error message in exception and sets the board size with
    * DEFAULT_BOARD_SIZE
    */
	try
	{
		errorCode = CPosition::setBoardDimension(rowCount,columnCount);
		if(errorCode != VALID_SIZE)
		{
			throw errorCode ;
		}
	}
	catch(PositionErrorCode_t& errorCode)
	{
		cout<<" Creating board with default size(3) due to the error code ::> "<<errorCode<<endl;
		CPosition::setBoardDimension(DEFAULT_BOARD_SIZE,DEFAULT_BOARD_SIZE);
	}

	/* Creates the board with the specified board size */
	createBoard(CPosition::m_rowCount,CPosition::m_columnCount);

	/* Initializes the board to EMPTY state */
	initializeBoard(CPosition::m_rowCount,CPosition::m_columnCount);
}

/*
 * Creates a 2D board for the game using the row size and column size
 */
void CBoard::createBoard(int rowCount, int columnCount)
{
	int rowIndex = 0 ;
	m_pBoard = new BoardState_t*[rowCount];
	for (rowIndex =0 ; rowIndex < rowCount;rowIndex++)
	{
		m_pBoard[rowIndex]= new BoardState_t[columnCount];
	}
}

/*
 * Initializes the 2D board with EMPTY state
 */
void CBoard::initializeBoard(int rowCount, int columnCount)
{
	for (int rowIndex = 0 ; rowIndex < rowCount; rowIndex++)
	{
		for(int columnIndex = 0 ; columnIndex < columnCount; columnIndex++)
		{
			m_pBoard[rowIndex][columnIndex] = EMPTY;
		}
	}
}

/*
 * Frees the memory used for the board.
 */
CBoard::~CBoard()
{

    for (int rowIndex = 0 ; rowIndex < CPosition::m_rowCount; rowIndex++)
    {
    	delete[] m_pBoard[rowIndex]; // clean up already allocated rows
    }

    delete[] m_pBoard;
}
