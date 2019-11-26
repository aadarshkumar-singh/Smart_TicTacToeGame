/***************************************************************************
****************************************************************************
 * \file CTicTacToeConsoleView.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeConsoleView.h
 *
 * Class for displaying the board and the result of the game in console View
 *
*************************************************************************/

#ifndef CTICTACTOECONSOLEVIEW_H_
#define CTICTACTOECONSOLEVIEW_H_

#include "CScreen.h"


class CTicTacToeConsoleView : public CScreen
{

public:

	/**
	 * Initializes the instances with the address of the board, row size and the column size
	 * respectively.
	 *
	 * @param ticTacToeBoardView : Pointer to store the address of the board
	 * @param rowSize : row size of the board
	 * @param columnSize : column size of the board
	 */
	CTicTacToeConsoleView(BoardState_t **ticTacToeBoardView,int rowSize, int columnSize);

	/**
	 * To print the board on a console view screen
	 */
	void printScreen();

	/**
	 * To print the result of the board game on a console view screen
	 * @param Player : The player who has won
	 * @param winTile: The tile that the winner player was playing with
	 * @param result : If the game has resulted in a win/draw.
	 */
	void printResult(gamePlayers_t Player,BoardState_t winTile,gameResult_t result);
	/**
	 * Destructor of the Class CTicTacToeConsoleView
	 */
	~CTicTacToeConsoleView();
};

#endif /* CTICTACTOECONSOLEVIEW_H_ */
