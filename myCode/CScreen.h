/*
 * CScreen.h
 *
 *  Created on: Nov 18, 2019
 *      Author: Aadarshxp
 */

#ifndef CSCREEN_H_
#define CSCREEN_H_

#include "CBoard.h"
#include "CPlayer.h"

class CScreen
{
protected:
	BoardState_t **m_ticTacToeBoardView;

public:
	CScreen();
	CScreen(BoardState_t **ticTacToeBoardView);
	virtual void printScreen(int rowSize,int columnSize)=0;
	virtual void printResult(gamePlayers_t Player,BoardState_t winTile) = 0;
	virtual ~CScreen();
};

#endif /* CSCREEN_H_ */
