/***************************************************************************
****************************************************************************
 * \file CComputerPlayer.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CComputerPlayer.h
 *
 * Class for the Computer player for the tictactoe board game,
 * This class defines the API to place the move of the computer player on the board.
 *
 * \note The computer decides to attack , defend or block fork as per the
 * 		 Opponents move. Computer may never lose.
*************************************************************************/

#ifndef CCOMPUTERPLAYER_H_
#define CCOMPUTERPLAYER_H_

#include "CPlayer.h"
#include "CPosition.h"


/**
 * \brief Maximum number of moves possible to play initially
 *        to maximize win probability
 */
#define POSSIBLE_INITIAL_WINING_MOVES 5
/**
 * \brief Flag to decide the moves based on all Possible
 *        Tiles/Squares on the Board
 */
enum playerMoves_e
{
	MOVE_EMPTY_BOARD,  //!< MOVE_EMPTY_BOARD   : Move when the board empty.
	MOVE_CORNER,       //!< MOVE_CORNER        : Move when corner empty.
	MOVE_EDGE,         //!< MOVE_EDGE          : Move when edge empty.
	MOVE_ATTACKORBLOCK,//!< MOVE_ATTACKORBLOCK : Move when in winning or losing situation.
};
typedef playerMoves_e playerMoves_t ;

/**
 * \brief Defines all possiblities for the move.
 *        If available,unavailable,winning move or not winning move.
 */
enum moveAvailablity_e
{
	UNAVAILABLE,       //!< UNAVAILABLE       : If its not possible to move to the tile/square.
	AVAILABLE,         //!< AVAILABLE         : If its possible  to move to the tile/square.
	NOT_A_WINNING_MOVE,//!< NOT_A_WINNING_MOVE: If its not a winning move on the board.
	IS_WINNING_MOVE,   //!< IS_WINNING_MOVE   : If its winning move on the board.
};
typedef moveAvailablity_e moveAvailablity_t;

/**
 * \brief Positions on Board
 */
enum boardPosition_e
{
	POSITION_ZERO,//!< POSITION_ZERO : Row/Column position as zero
	POSITION_ONE, //!< POSITION_ONE  : Row/Column position as one
	POSITION_TWO, //!< POSITION_TWO  : Row/Column position as two
};
typedef boardPosition_e boardPosition_t;

/**
 * \brief This class defines the API to place the move of the computer player on the board.
 * \note  The computer decides to attack , defend or block fork as per the
 * 		  Opponents move. Computer may never lose.
 */
class CComputerPlayer:public CPlayer
{
	/**
	 * \brief Position Class Object to get the Board Dimension.
	 */
	CPosition m_boardSize;

	/**
	 * \brief Pointer of enum type BoardState_t to store the address of the board.
	 */
	BoardState_t **m_playerBoard;

	/**
	 * \brief Best Possible Row Position to place the tile on the board
	 */
	int m_bestRow;

	/**
	 * \brief Best Possible Column Position to place the tile on the board
	 */
	int m_bestColumn;

	/**
	 * \brief API to decide the best possible row and column based on the current
	 *        state of the board.
	 * @details decides best move by checking the current state of board in the order :
	 * 			    \n-  empty board
	 * 				\n-  computer can win in next move
	 * 				\n-  needs to stop opponent from winning
	 * 				\n-  block opponent fork
	 * 				\n-  empty corner
	 * 				\n-  empty side
	 * @param tileinfo: Tile that the Computer player is going to place on the board.
	 */
	void findBestMove(BoardState_t tileinfo);

	/**
	 * \brief This API checks if player tile is placed on any of the empty squares on board
	 *        will result in a win or not.
	 * @param playerTile : Tile of the computer or its opponent
	 * @return moveAvailablity_t: NOT_A_WINNING_MOVE: If its not a winning move on the board.
	 * 							  IS_WINNING_MOVE   : If its winning move on the board.
	 */
	moveAvailablity_t checkIfWon(BoardState_t playerTile);

	/**
	 * \brief 	This API sets the best row and column position based on the @param checkMove
	 *          passed as a parameter if the move is available else returns unavailable move.
	 * @param   playerTile :  Tile of the computer or its opponent
	 * @param   checkMove : playerMoves_t : All Possible Moves available on the board
	 * @return  moveAvailablity_t: UNAVAILABLE: If its not possible to move to the tile/square.
	 * 							  AVAILABLE  : If its possible  to move to the tile/square.
	 * 							  NOT_A_WINNING_MOVE: If its not a winning move on the board.
	 * 							  IS_WINNING_MOVE   : If its winning move on the board.
	 */
	moveAvailablity_t checkToAttackBlockOrPlace(BoardState_t playerTile,playerMoves_t checkMove);

	/**
	 * \brief  Checks if opponent is trying to create fork and blocks it.
	 * @param  playerTile :  Tile of the computer or its opponent
	 * @return moveAvailablity_t: UNAVAILABLE: If its not a fork situation.
	 * 							  AVAILABLE  : If its fork,sets row and column position
	 * 							  to block fork.
	 */
	moveAvailablity_t blockFork(BoardState_t playerTile);

public:

	/**
	 * Default constructor which initialises the m_playerBoard pointer to NULL
	 * and best row and column to zero
	 */
	CComputerPlayer();

	/**
	 * \brief Initializes the double Pointer m_playerBoard with the address
	 *        of the TicTacToe board
	 * @param pboard : Pointer to the TicTacToe board
	 */
	CComputerPlayer(BoardState_t **pboard);

	/**
	 * \brief API to place the move of Computer Player
	 * @param tileinfo : Tile that the Computer player is going to place on the board.
	 * \note  The computer enters into the board only when the best row and position
	 *        is empty otherwise throws an error message and find the best move again.
	 */
	void placeTile(BoardState_t tileinfo);

	/**
	 * \brief Destructor of the CComputerPlayer class to free the memory of the
	 *        pointer m_playerBoard that stores address of the board.
	 */
	~CComputerPlayer();
};

#endif /* CCOMPUTERPLAYER_H_ */
