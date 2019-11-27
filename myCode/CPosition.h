/***************************************************************************
****************************************************************************
 * \file CPosition.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CPosition.h
 * This class sets the board dimension as specified, if the specified
 * dimension is invalid it returns error.
 * It also gets the row and column position from player if he wants to
 * place the tile on the board, if the position given by the player is
 * out of board , it asks to give input again.
 *
*************************************************************************/

#ifndef CPOSITION_H_
#define CPOSITION_H_


/**
 * \brief Defines the possible error codes of the CPOSITION class.
 */
enum PositionErrorCode_e
{
	INVALID_ROW_SIZE,        //!< INVALID_ROW_SIZE : Row size is invalid
	INVALID_COLUMN_SIZE,     //!< INVALID_COLUMN_SIZE : Column size is invalid
	INVALID_ROW_POSITION,    //!< INVALID_ROW_POSITION : Row Position is invalid
	INVALID_COLUMN_POSITION, //!< INVALID_COLUMN_POSITION : Column Position is invalid
	VALID_SIZE,				 //!< VALID_SIZE : dimension of board is valid
	VALID_POSITION,			 //!< VALID_POSITION: position given by player is valid
};
typedef PositionErrorCode_e PositionErrorCode_t;

/**
 * \brief sets valid board dimensions specified, if dimensions are invalid returns error.
 *        Gets the row and column position from the player so that it can place the tile
 *        as specified by the player on board. If invalid asks the player to enter the
 *        move again.
 */
class CPosition
{
	/**
	 * \brief Row Size of the Board
	 */
	static int m_rowCount;

	/**
	 * \brief Column Size of the Board
	 */
	static int m_columnCount;

	/**
	 * \brief Row Position where the player wants to place the tile
	 */
	int m_rowPosition;

	/**
	 * \brief Column Position where the player wants to place the tile
	 */
	int m_columnPosition;

	/**
	 * \brief  Sets the Board dimension , If invalid dimension is given returns error
	 * @param  rowCount : Row Size of the board
	 * @param  columnCount : Column Size of the board
	 * @return VALID_SIZE : dimension of board is valid
	 * 		   INVALID_ROW_SIZE : Row size is invalid
	 * 		   INVALID_COLUMN_SIZE : Column size is invalid
	 */
	static PositionErrorCode_t setBoardDimension(int rowCount,int columnCount);

public:
	/**
	 * \brief Default Constructor to initialize the row and column Position
	 *        that the player will set to place the tile on the board.
	 */
	CPosition();

	/**
	 * \brief  Returns the valid row Position specified by the player.
	 * @return valid row Position specified by the player.
	 */
	int getRowPosition();

	/**
	 * \brief  Returns the valid column Position specified by the player
	 * @return valid column Position specified by the player
	 */
	int getColumnPosition();

	/**
	 * \brief Gets the row and the column position for the move on the board from the player.
	 * \note  If player enters position out of board dimension throws an error and asks the
	 *        player to enter the position again.
	 */
	void getMoveFromPlayer();
	/**
	 * \brief  Returns the Row Dimension of the Board
	 * @return Valid Row dimension of the board.
	 */
	static int getBoardRowSize();

	/**
	 * \brief  Returns the Column Dimension of the Board
	 * @return Valid Column Dimension of the board.
	 */
	static int getBoardColumnSize();

	/**
	 * \brief CTicTacToeBoard is friend class of CPosition Class
	 */
	friend class CTicTacToeBoard;

	/**
	 * \brief CBoard is friend class of CPosition Class
	 */
	friend class CBoard;
};

#endif /* CPOSITION_H_ */
