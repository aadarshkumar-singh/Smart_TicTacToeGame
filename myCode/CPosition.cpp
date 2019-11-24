/*
 * CPosition.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: Aadarshxp
 */

#include "CPosition.h"
#include "iostream"

using namespace std;
/**
 *
 */
int CPosition::m_rowCount;

/**
 *
 */
int CPosition::m_columnCount;

CPosition::CPosition()
{
	m_rowPosition = 0;
	m_columnPosition = 0;
}

int CPosition::getRowPosition()
{
	return (m_rowPosition);
}

int CPosition::getColumnPosition()
{
	return(m_columnPosition);
}

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

int CPosition::getBoardRowSize()
{
	return (m_rowCount);
}

int CPosition::getBoardColumnSize()
{
	return(m_columnCount);
}
