/*
 * CTicTacToeGame.h
 *
 *  Created on: Nov 18, 2019
 *      Author: Aadarshxp
 */

#ifndef CTICTACTOEGAME_H_
#define CTICTACTOEGAME_H_

#include  "CTicTacToeBoard.h"

#define MAXIMUM_POSIBLE_MOVES 9

class CTicTacToeGame
{
	CTicTacToeBoard *m_ticTacToeBoard;

public:
	CTicTacToeGame();
	void play();
	virtual ~CTicTacToeGame();
};

#endif /* CTICTACTOEGAME_H_ */
