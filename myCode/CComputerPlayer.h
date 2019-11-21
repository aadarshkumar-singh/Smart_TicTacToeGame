/*
 * CComputerPlayer.h
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#ifndef CCOMPUTERPLAYER_H_
#define CCOMPUTERPLAYER_H_

#include "CPlayer.h"

class CComputerPlayer:public CPlayer
{
public:
	CComputerPlayer();
	void placeTile(BoardState_t tileinfo,BoardState_t **board);
	virtual ~CComputerPlayer();
};

#endif /* CCOMPUTERPLAYER_H_ */
