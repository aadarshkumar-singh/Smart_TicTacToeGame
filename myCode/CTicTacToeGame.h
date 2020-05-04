/***************************************************************************
****************************************************************************
 * \file CTicTacToeGame.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeGame.h
 * The Logic to play the tictactoe game is implemented in this class.
 * There are maximum of 9 moves. Each player take turns, First Player 1 plays the move
 * followed by player 2 and if the player has won or game is draw the result is
 * displayed on the screen.
 *
****************************************************************************/


#ifndef CTICTACTOEGAME_H_
#define CTICTACTOEGAME_H_

#include  "CTicTacToeBoard.h"

/**
 * \brief Maximum Number of Moves in the TicTacToe Game.
 */
#define MAXIMUM_POSIBLE_MOVES 9

/**
 * \brief This class has the method that implements the game play logic of tictactoe
 *        Game. There are maximum of 9 moves, each player take turns and
 * 		  if the player has won or game is draw the result is displayed on the screen.
 */
class CTicTacToeGame
{
	/**
	 * \brief Pointer that stores the address of the TicTacToe Board
	 */
	CTicTacToeBoard *m_ticTacToeBoard;
	/**
	 * \brief  Checks if a player has won or game is draw
	 * @param  playerTile : Tile that the player places on the board
	 * @return PLAYER_WON    : if game has ended in one of the player winning
	 * 		   PLAYER_PLAYING: if game is still in progress
	 * 		   PLAYER_DRAW,	 : if game has ended in a draw
	 */
	gameResult_t checkGameResult(BoardState_t playerTile);

	/**
	 * \brief  Checks if the game has been finished
	 * @return PLAYER_PLAYING: if game is still in progress
	 * 		   PLAYER_DRAW,	 : if game has ended in a draw
	 */
	gameResult_t checkBoardFull();

public:
	/**
	 * Constructor that initializes the pointer m_ticTacToeBoard
	 * to store the address of tictactoe board
	 */
	CTicTacToeGame();

	/**
	 * \brief This API is used to play the tictactoe game
	 */
	void play();

	/**
	 * \brief Frees the memory of the m_ticTacToeBoard pointer that
	 *        points to the tictactoe board
	 */
	~CTicTacToeGame();
};

#endif /* CTICTACTOEGAME_H_ */
