/***************************************************************************
****************************************************************************
 * \file CHumanPlayer.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CHumanPlayer.h
 *
 * Class for the Human player for the tictactoe board game,
 * This class defines the API to place the move of the human player on the board.
 *
 * \note If human makes invalid move , it asks the user again to enter the
 *       coordinates
*************************************************************************/

#ifndef CHUMANPLAYER_H_
#define CHUMANPLAYER_H_

#include "CPlayer.h"
#include "CPosition.h"

/**
 * \brief This class defines the API to place the move of the human player on the board.
 * \note If human makes invalid move , it asks the user again to enter the
 *       coordinates
 */
class CHumanPlayer: public CPlayer
{
	/**
	 * \brief Object of the Position Class to set the coordinate for the move
	 *        which Human player makes. Also to get the Board Dimension.
	 */
	CPosition m_playerPosition;

	/**
	 * \brief Pointer of enum type BoardState_t to store the address of the board.
	 */
	BoardState_t **m_playerboard;

public:

	/**
	 * \brief Initializes the double Pointer m_playerboard with the address
	 *        of the TicTacToe board
	 * @param playerboard : Pointer to the TicTacToe board
	 */
	CHumanPlayer(BoardState_t **playerboard);

	/**
	 * \brief API to place the move of Human Player
	 * @param tileinfo : Tile that the Human player is going to place on the board.
	 * \note  If the user enters invalid coordinate it asks the user to enter the
	 * 		  move coordinates again
	 */
	void placeTile(BoardState_t tileinfo);

	/**
	 * \brief Destructor of the CHumanPlayer class to free the memory of the pointer
	 * 		  resource of the class that stores address of the board.
	 */
	~CHumanPlayer();
};

#endif /* CHUMANPLAYER_H_ */
