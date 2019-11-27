/***************************************************************************
****************************************************************************
 * \file CTicTacToeBoard.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeBoard.h
 *
 * Class that has methods to create the TicTacToe Board, Create players
 * For the TicTacToe Board based on the user selection of players,
 * create a screen for displaying the board and the result of the game.
 * \note The supported players are humans and computer, and screen is console
 *       view screen.
 *
****************************************************************************/

#ifndef CTICTACTOEBOARD_H_
#define CTICTACTOEBOARD_H_

#include "CBoard.h"
#include "CTicTacToeConsoleView.h"
#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"

/**
 * \brief Number of rows of the tictactoe board
 */
#define TICTACTOE_ROW_SIZE 3

/**
 * \brief Number of Columns of the tictactoe board
 */
#define TICTACTOE_COLUMN_SIZE 3

/**
 * \brief Creates a 3x3 TicTacToe Board, creates player for the TicTacToe
 *        Board based on user selection(Human/Computer).Creates a screen
 *        for displaying the board and the result of the game.
 */
class CTicTacToeBoard : public CBoard
{
	/**
	 * \brief Pointer that stores the address of the console view screen created
	 */
	CScreen *m_screen;

	/**
	 * \brief Pointer that stores the address of player 1 that is selected by user
	 */
	CPlayer *m_player1;

	/**
	 * \brief Pointer that stores the address of player 2 that is selected by user
	 */
	CPlayer *m_player2;

	/**
	 * \brief  Gets input from the user about the the type of player
	 * @param  index : Player Number (Player1/Player2)
	 * @return HUMAN_PLAYER   : Player is human
	 * 		   COMPUTER_PLAYER: Player is computer
	 */
	playerInfo_t selectBoardPlayers(gamePlayers_t index);

	/**
	 * \brief Based on the players selected by the user
	 *        create player1 and player 2.
	 */
	void createSelectedPlayers();

	/**
	 * \brief Creates Player 1 , it can be human/Computer based on selection
	 * 		  From the user
	 */
	void createPlayer1();

	/**
	 * \brief Creates Player 2 , it can be human/Computer based on selection
	 * 		  From the user
	 */
	void createPLayer2();

public:
	/**
	 *
	 * \brief Constructor that Initializes the generic board to  a 3x3 TicTacToe Board,
	 *        creates a console view screen and create players based on user selection
	 */
	CTicTacToeBoard();

	/**
	 * \brief Displays the TicTacToe Board
	 */
	void displayBoard();

	/**
	 * \brief Displays the Result of the TicTacToe Game. It says which Player has won or
	 *        the game has finished in a draw.
	 * @param Player : Player who has a (win/draw) in the game Player 1 / Player 2
	 * @param winTile : Tile of the player who has won (x/o)
	 * @param result  : If the game has winner or its a draw.
	 */
	void displayResult(gamePlayers_t Player, BoardState_t winTile, gameResult_t result);

	/**
	 * \brief Returns the address of the player1 object of type CPlayer
	 *        created based on user selection
	 * @return address of the player1 of type CPlayer
	 */
	CPlayer* getBoardPlayer1();

	/**
	 * \brief Returns the address of the player2 object of type CPlayer
	 *        created based on user selection
	 * @return address of the player2 of type CPlayer
	 */
	CPlayer* getBoardPlayer2();
	/**
	 * \brief  Returns the address of the TicTacToe board
	 * @return Double pointer that points to 2 dimension board of type BoardState_t
	 */
	BoardState_t** getTicTacToeBoard();
	/**
	 * \brief Destructor to free the memory of the pointer resource of the class that
	 * 		  stores address of the player 1 , player 2 and screen.
	 */
	~CTicTacToeBoard();
};

#endif /* CTICTACTOEBOARD_H_ */
