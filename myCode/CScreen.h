/***************************************************************************
****************************************************************************
 * \file CScreen.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CScreen.h
 *
 * Base Class for displaying the board and the result of the game.
 * It is used for creating a generic way of displaying the results and the board.
 * The user can show the result in the console view,graphical view etc.
 *
 *\note : In the application display using console view is defined and functional
 * 		  Graphical view is defined but the functionality needs to be extended.
 * 		  If required other screen can also be extended.
 *
*************************************************************************/

#ifndef CSCREEN_H_
#define CSCREEN_H_

#include "CBoard.h"
#include "CPlayer.h"

/**
 * \brief prints the board and the result of the game on any defined screen.
 */
class CScreen
{
protected:
	/**
	 * \brief Pointer object to store the address of the board.
	 */
	BoardState_t **m_pticTacToeBoardView;
	/**
	 * \brief Row size of the board needed for displaying board.
	 */
	int m_boardRowSize;
	/**
	 * \brief Column size of the board needed for displaying board.
	 */
	int m_boardColumnSize;

public:
	/**
	 * \brief Default constructor to initialize pointer to NULL,
	 * 		  and other members to zero.
	 */
	CScreen();

	/**
	 * \brief Initializes the instances with the address of the board,
	 * 		  row size and the column size respectively.
	 * @param ticTacToeBoardView : Pointer to store the address of the board
	 * @param rowSize : row size of the board
	 * @param columnSize : column size of the board
	 */
	CScreen(BoardState_t **ticTacToeBoardView,int rowSize, int columnSize);

	/**
	 * \brief To print the board on any defined screen.
	 * \note  The derived class of this class must have this API
	 * 		  otherwise compiler throws error
	 */
	virtual void printBoard()=0;

	/**
	 * \brief To print the result of the board game on any defined screen.
	 * @param Player : The player who has won
	 * @param winTile: The tile that the winner player was playing with
	 * @param result : If the game has resulted in a win/draw.
	 * \note  The derived class of this class must have this API
	 * 		  otherwise compiler throws error.
	 */
	virtual void printResult(gamePlayers_t Player,BoardState_t winTile,gameResult_t result) = 0;

	/**
	 * \brief Destructor of the CScreen class to free the memory of the pointer
	 * 		  resource of the class that stores address of the board.
	 */
	virtual ~CScreen();
};

#endif /* CSCREEN_H_ */
