/***************************************************************************
 ****************************************************************************
 * \file CTicTacToeGraphicalView.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeGraphicalView.cpp
 *
 * Source file for the Class CTicTacToeGraphicalView for
 * displaying the board and the result of the game in graphical
 * View
 *
 * \note This is not implemented yet , can be extended later on
 * by using the class methods.
 *
 *************************************************************************/

#include "CTicTacToeGraphicalView.h"

/*
 * Initializes the instances with the address of the board, row size and the column size
 * respectively.
 *
 * @param ticTacToeBoardView : Pointer to store the address of the board
 * @param rowSize : row size of the board
 * @param columnSize : column size of the board
 */
CTicTacToeGraphicalView::CTicTacToeGraphicalView(
		BoardState_t **ticTacToeBoardView, int rowSize, int columnSize)
{
	// To be supported later
}

/*
 * To print the board on a graphical screen
 */
void CTicTacToeGraphicalView::printBoard()
{
	// To be supported later

}

/*
 * To print the result of the board game on a graphical screen
 * @param Player : The player who has won
 * @param winTile: The tile that the winner player was playing with
 * @param result : If the game has resulted in a win/draw.
 */
void CTicTacToeGraphicalView::printResult(gamePlayers_t Player,
		BoardState_t winTile, gameResult_t result)
{
	// To be supported later
}

/*
 * Destructor of the class Graphical view
 */
CTicTacToeGraphicalView::~CTicTacToeGraphicalView()
{
	// To be supported later
}
