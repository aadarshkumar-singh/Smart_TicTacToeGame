/**
 * \file CPosition.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CPosition.h
 *
 * - sets the board Dimensions
 * - Gets the coordinates (row and column) from the user to place
 *   the tile in the board.
 *
 * \note
 *
 */

#ifndef CPOSITION_H_
#define CPOSITION_H_

/**
 * \brief Defines the possible error codes of the CPOSITION class.
 */
enum PositionErrorCode_e
{
	INVALID_ROW_SIZE,        //!< INVALID_ROW_SIZE
	INVALID_COLUMN_SIZE,     //!< INVALID_COLUMN_SIZE
	INVALID_ROW_POSITION,    //!< INVALID_ROW_POSITION
	INVALID_COLUMN_POSITION, //!< INVALID_COLUMN_POSITION
	VALID_SIZE,				 //!< VALID_SIZE
	VALID_POSITION,			 //!< VALID_POSITION
};
typedef PositionErrorCode_e PositionErrorCode_t;

class CPosition
{

	static int m_rowCount;
	static int m_columnCount;
	int m_rowPosition;
	int m_columnPosition;
	static PositionErrorCode_t setBoardDimension(int rowCount,int columnCount);

public:
	CPosition();
	int getRowPosition();
	int getColumnPosition();
	void getMoveFromPlayer();
	static int getBoardRowSize();
	static int getBoardColumnSize();
	friend class CTicTacToeBoard;
	friend class CBoard;
};

#endif /* CPOSITION_H_ */
