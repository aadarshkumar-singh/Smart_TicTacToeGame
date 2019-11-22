/*
 * CTicTacToeGame.h
 *
 *  Created on: Nov 18, 2019
 *      Author: Aadarshxp
 */

#ifndef CTICTACTOEGAME_H_
#define CTICTACTOEGAME_H_

#include  "CTicTacToeBoard.h"

/**
 *
 */
#define MAXIMUM_POSIBLE_MOVES 9
/**
 *
 */
#define FIRST_ROW_INDEX     0
/**
 *
 */
#define SECOND_ROW_INDEX    1
/**
 *
 */
#define THIRD_ROW_INDEX     2
/**
 *
 */
#define FIRST_COLUMN_INDEX  0
/**
 *
 */
#define SECOND_COLUMN_INDEX 1
/**
 *
 */
#define THIRD_COLUMN_INDEX  2

class CTicTacToeGame
{
	CTicTacToeBoard *m_ticTacToeBoard;
	gameResult_t checkGameResult(BoardState_t playerTile);
	gameResult_t checkRowForResult(BoardState_t playerTile);
	gameResult_t checkColumnForResult(BoardState_t playerTile);
	gameResult_t checkPrimaryDiagnolForResult(BoardState_t playerTile);
	gameResult_t checkSecondaryDiagnolForResult(BoardState_t playerTile);
	gameResult_t checkBoardFull();



public:
	CTicTacToeGame();
	void play();

	virtual ~CTicTacToeGame();
};

#endif /* CTICTACTOEGAME_H_ */
