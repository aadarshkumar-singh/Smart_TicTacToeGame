/*
 * CPlayer.h
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#ifndef CPLAYER_H_
#define CPLAYER_H_

#include "CBoard.h"

/**
 * Defines the player i.e. if player is human/computer/invalid
 */
enum playerInfo_e
{
	HUMAN_PLAYER, 	 //!< HUMAN_PLAYER   : Player to provide next move is human
	COMPUTER_PLAYER, //!< COMPUTER_PLAYER: Player to provide next move is computer
};
typedef playerInfo_e playerInfo_t ;

enum gamePlayers_e
{
	PLAYER1 = 1,
	PLAYER2,
};
typedef gamePlayers_e gamePlayers_t;

class CPlayer
{
private:


public:
	CPlayer();
	virtual void placeTile(BoardState_t tileinfo)=0;
	virtual ~CPlayer();
};

#endif /* CPLAYER_H_ */
