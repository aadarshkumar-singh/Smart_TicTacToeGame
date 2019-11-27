/***************************************************************************
****************************************************************************
 * \file CTicTacToeGraphicalView.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeGraphicalView.h
 *
 * Class for displaying the board and the result of the game in graphical
 * View
 *
 * \note This is not implemented yet , can be extended later on
 * by using the class methods.
 *
*************************************************************************/


#ifndef CTICTACTOEGRAPHICALVIEW_H_
#define CTICTACTOEGRAPHICALVIEW_H_

#include "CScreen.h"

/**
 * \brief prints the board and the result of the game on graphical view screen.
 * \note  Graphical view is not implemented yet , but can be extended later on by using
 *        the methods defined in this class.
 */
class CTicTacToeGraphicalView : public CScreen
{
public:

	/**
	 * \brief Initializes the instances with the address of the board, row size and the column size
	 * 		  respectively.
	 *
	 * @param ticTacToeBoardView : Pointer to store the address of the board
	 * @param rowSize : row size of the board
	 * @param columnSize : column size of the board
	 */
	CTicTacToeGraphicalView(BoardState_t **ticTacToeBoardView,int rowSize, int columnSize);

	/**
	 * \brief To print the board on a graphical screen
	 * \note  Printing Board on a graphical screen is not implemented yet ,
	 *        can be extended easily on modifying this API as per requirements.
	 */
	void printBoard();

	/**
	 * \brief To print the result of the board game on a graphical screen
	 * @param Player : The player who has won
	 * @param winTile: The tile that the winner player was playing with
	 * @param result : If the game has resulted in a win/draw.
	 * \note  Printing result on a graphical screen is not implemented yet ,
	 *        can be extended easily on modifying this API as per requirements.
	 */
	void printResult(gamePlayers_t Player,BoardState_t winTile,gameResult_t result);

	/**
	 * \brief Destructor of the class Graphical view
	 */
	~CTicTacToeGraphicalView();
};

#endif /* CTICTACTOEGRAPHICALVIEW_H_ */
