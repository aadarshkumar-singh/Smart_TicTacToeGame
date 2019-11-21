/*
 * CTicTacToeConsoleView.h
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#ifndef CTICTACTOECONSOLEVIEW_H_
#define CTICTACTOECONSOLEVIEW_H_

#include "CScreen.h"

class CTicTacToeConsoleView : public CScreen
{

public:
	CTicTacToeConsoleView(BoardState_t **ticTacToeBoardView);
	void printScreen(int rowSize,int columnSize);
	virtual ~CTicTacToeConsoleView();
};

#endif /* CTICTACTOECONSOLEVIEW_H_ */
