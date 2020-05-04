/***************************************************************************
****************************************************************************
 * \file CScreen.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CScreen.cpp
 *
 * Source file for the Base Class CScreen for displaying the board and the result
 * of the game. It is used for creating a generic way of displaying the results
 * and the board.The user can show the result in the console view,graphical view etc.
 *
*************************************************************************/
#include "CScreen.h"
#include "iostream"

using namespace std;

/*
 * Default constructor to initialize pointer to NULL,
 * and other members to zero.
 */
CScreen::CScreen()
{
	m_pticTacToeBoardView = NULL;
	m_boardRowSize = 0;
	m_boardColumnSize = 0;
}

/*
 * Initializes the instances with the address of the board, row size and the column size
 * respectively.
 *
 * @param ticTacToeBoardView : Pointer to store the address of the board
 * @param rowSize : row size of the board
 * @param columnSize : column size of the board
 */
CScreen::CScreen(BoardState_t **ticTacToeBoardView,int rowSize, int columnSize)
{
	m_pticTacToeBoardView =ticTacToeBoardView;
	m_boardRowSize = rowSize;
	m_boardColumnSize =columnSize;
}

/*
 * Destructor of the CScreen class to free the memory of the pointer
 * resource of the class that stores address of the board.s
 */

CScreen::~CScreen()
{
	for (int rowIndex = 0 ; rowIndex < m_boardRowSize ; rowIndex++)
	{
		delete[] m_pticTacToeBoardView[rowIndex]; // clean up already allocated rows
	}

	delete[] m_pticTacToeBoardView;

}
