/*
 * CBoard.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: Aadarshxp
 */

#include "CBoard.h"
#include "CPosition.h"
#include "iostream"

using namespace std;

CBoard::CBoard(int rowCount,int columnCount)
{
	PositionErrorCode_t errorCode;

	try
	{
		errorCode = CPosition::setBoardDimension(rowCount,columnCount);
		if(errorCode != VALID_SIZE)
		{
			throw errorCode ;
		}
		else
		{
			createBoard(CPosition::m_rowCount,CPosition::m_columnCount);
			initializeBoard(CPosition::m_rowCount,CPosition::m_columnCount);
		}
	}
	catch(PositionErrorCode_t& errorCode)
	{
		cout<<"Terminated due to "<<errorCode<<endl;
	}

}

void CBoard::createBoard(int rowCount, int columnCount)
{

	//ToDo : error handling check gmail
	int rowIndex = 0 ;
	m_pBoard = new BoardState_t*[rowCount];
	for (rowIndex =0 ; rowIndex < rowCount;rowIndex++)
	{
		m_pBoard[rowIndex]= new BoardState_t[columnCount];
	}

}

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


CBoard::~CBoard()
{

    for (int rowIndex = 0 ; rowIndex < CPosition::m_rowCount; rowIndex++)
    {
    	delete[] m_pBoard[rowIndex]; // clean up already allocated rows
    }

    delete[] m_pBoard;
}

