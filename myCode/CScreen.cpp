/*
 * CScreen.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: Aadarshxp
 */

#include "CScreen.h"
#include "iostream"

using namespace std;

CScreen::CScreen()
{
	m_ticTacToeBoardView = NULL;
	m_boardRowSize = 0;
	m_boardColumnSize = 0;
}

CScreen::CScreen(BoardState_t **ticTacToeBoardView,int rowSize, int columnSize)
{
	// TODO Auto-generated constructor stub

	m_ticTacToeBoardView =ticTacToeBoardView;
	m_boardRowSize = rowSize;
	m_boardColumnSize =columnSize;
}

CScreen::~CScreen()
{
	for (int rowIndex = 0 ; rowIndex < m_boardRowSize ; rowIndex++)
	{
		delete[] m_ticTacToeBoardView[rowIndex]; // clean up already allocated rows
	}

	delete[] m_ticTacToeBoardView;

}
