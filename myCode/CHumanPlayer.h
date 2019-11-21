/*
 * CHumanPlayer.h
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#ifndef CHUMANPLAYER_H_
#define CHUMANPLAYER_H_

#include "CPlayer.h"
#include "CPosition.h"

class CHumanPlayer: public CPlayer
{
	CPosition m_playerPosition;
public:
	CHumanPlayer();
	void placeTile(BoardState_t tileinfo,BoardState_t **board);
	virtual ~CHumanPlayer();
};

#endif /* CHUMANPLAYER_H_ */
