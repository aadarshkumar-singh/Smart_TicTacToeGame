/***************************************************************************
****************************************************************************
 * \file CBoard.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CBoard.h
 *
 * Class for creating and initializing a Generic board for any Board game
 *
 * \note If the size of row and column to be set is invalid , then
 *  	 a 2D board with DEFAULT_BOARD_SIZE is created and initialized.
 *
****************************************************************************/

#ifndef CBOARD_H_
#define CBOARD_H_

/**
 * \brief defines the state of the board tiles , if empty or
 *   	  occupied by player1/player2.
 */
enum BoardState_e
{
	EMPTY = '.',   //!< EMPTY : if board tile is empty
	TILE_X='x',	   //!< TILE_X : if board tile is occupied by player 1
	TILE_O='o',	   //!< TILE_O : if board tile is occupied by player 2
};
typedef BoardState_e BoardState_t;

/**
 * Defines the Status of the game
 */
enum gameResult_e
{
	PLAYER_WON, 	//!< PLAYER_WON if game has ended in one of the player winning
	PLAYER_PLAYING, //!< PLAYER_PLAYING if game is still in progress
	PLAYER_DRAW,	//!< PLAYER_DRAW if game has ended in a draw
};
typedef enum gameResult_e gameResult_t;

/**
 * Default size of the board, if dimension provided by the user is invalid
 */
#define DEFAULT_BOARD_SIZE 3

/**
 * \brief Class represents a Generic Board.
 */
class CBoard
{
private:
	/**
	 * API to create a 2 dimensional board , based on the row size and
	 * column size passed as parameters
	 * @param rowCount : row size of the board
	 * @param columnCount : column size of the board
	 */
	void createBoard(int rowCount,int columnCount);

	/**
	 * API to initialize Board to an EMPTY state.
	 * @param rowCount : row size of the board
	 * @param columnCount: column size of the board
	 */
	void initializeBoard(int rowCount, int columnCount);

public:
	/**
	 * Sets the row size and the column size of the board,
	 * Creates and initializes the 2 dimensional Board for
	 * the game.
	 *
	 * @param rowCount : row size of the board to be set
	 * @param columnCount : column size of the board to be set
	 *
	 * \note :
	 * If the rowCount and the column count is invalid , then
	 * a 2D board with DEFAULT_BOARD_SIZE is created and initialized
	 */
	CBoard(int rowCount,int columnCount);

	/**
	 * Destructor of the CBoard, frees the allocated memory used
	 * up for the board.
	 */
	~CBoard();

protected:
	/**
	 * \brief Pointer to the 2 dimensional Board array
	 *  has an enum type BoardState_t which represents the state of the tile
	 *  empty or occupied by player1/player 2
	 */
	BoardState_t **m_pBoard;
};

#endif /* CBOARD_H_ */
