/**
 * \file CBoard.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CBoard.h
 *
 * Generic Class for creating a board for any Board game
 *
 * \note
 *
 */


#ifndef CBOARD_H_
#define CBOARD_H_

/**
 * \brief Default row size of the generic board
 */
#define DEFAULT_ROW_BOARDSIZE 3

/**
 * \brief Default column size of the generic board
 */
#define DEFAULT_COLUMN_BOARDSIZE 3

/**
 * \brief defines the state of the board tiles , if empty or
 *   	  occupied by player1/player2.
 */
enum BoardState_e
{
	EMPTY = '.',   //!< EMPTY : if board tile is empty
	TILE_X='x',//!< TILE_X : if board tile is occupied by player 1
	TILE_O='o',//!< TILE_O : if board tile is occupied by player 2
};
typedef BoardState_e BoardState_t;

class CBoard
{
private:
	void createBoard(int rowCount,int columnCount);
	void initializeBoard(int rowCount, int columnCount);

public:
	CBoard(int rowCount,int columnCount);
	BoardState_t getBoardStateAt();
	void setBoardStateAt(BoardState_t player);
	virtual ~CBoard();

protected:
	BoardState_t **m_pBoard;
};

#endif /* CBOARD_H_ */
