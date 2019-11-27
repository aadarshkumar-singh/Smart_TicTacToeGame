/***************************************************************************
****************************************************************************
 * \file CPlayer.h
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CPlayer.h
 *
 * Base Class for the players of the board game, It defines the API to place
 * the move of the player on the board. This player can be any defined player.
 * In reference to this application it can be either a Human or a Computer.
*************************************************************************/

#ifndef CPLAYER_H_
#define CPLAYER_H_

#include "CBoard.h"

/**
 * \brief Defines the type of player i.e. if player is human/computer/invalid
 */
enum playerInfo_e
{
	HUMAN_PLAYER, 	 //!< HUMAN_PLAYER   : Player is human
	COMPUTER_PLAYER, //!< COMPUTER_PLAYER: Player is computer
};
typedef playerInfo_e playerInfo_t ;

/**
 * \brief Defines the player list
 */
enum gamePlayers_e
{
	PLAYER1 = 1,//!< PLAYER1 : makes the move first
	PLAYER2,    //!< PLAYER2 : makes the move second
};
typedef gamePlayers_e gamePlayers_t;

/**
 * \brief Base Class for the players of the board game, It defines the API to place
 * 		  the move of the player on the board. This player can be any defined player.
 * \note  In reference to this application it can be either a Human or a Computer.
 */
class CPlayer
{
private:


public:

	/**
	 * \brief Default constructor of the CPlayer
	 */
	CPlayer();

	/**
	 * \brief API to place the move of any player, In this application
	 *        either a Human or aComputer
	 * @param tileinfo : Tile that the player is going to place on the board.
	 * \note  The derived class of this class must have this API
	 * 		  otherwise compiler throws error
	 */
	virtual void placeTile(BoardState_t tileinfo)=0;

	/**
	 * Default destructor of the CPlayer
	 */
	virtual ~CPlayer();
};

#endif /* CPLAYER_H_ */
