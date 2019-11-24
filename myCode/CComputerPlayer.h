/*
 * CComputerPlayer.h
 *
 *  Created on: Nov 21, 2019
 *      Author: Aadarshxp
 */

#ifndef CCOMPUTERPLAYER_H_
#define CCOMPUTERPLAYER_H_

#include "CPlayer.h"
#include "CPosition.h"

enum playerMoves_e
{
	MOVE_EMPTY_BOARD,
	MOVE_CORNER,
	MOVE_EDGE,
	MOVE_ATTACKORBLOCK,
};
typedef playerMoves_e playerMoves_t ;

enum moveAvailablity_e
{
	UNAVAILABLE,
	AVAILABLE,
	NOT_A_WINNING_MOVE,
	IS_WINNING_MOVE,
};
typedef moveAvailablity_e moveAvailablity_t;

class CComputerPlayer:public CPlayer
{
	CPosition m_boardSize;
	BoardState_t **m_playerBoard;
	int m_bestRow;
	int m_bestColumn;

	void findBestMove(BoardState_t tileinfo);
	moveAvailablity_t checkIfWon(BoardState_t playerTile);
	moveAvailablity_t checkToAttackBlockOrPlace(BoardState_t playerTile,playerMoves_t checkMove);
	moveAvailablity_t blockFork(BoardState_t playerTile);

public:
	CComputerPlayer();
	CComputerPlayer(BoardState_t **pboard);
	void placeTile(BoardState_t tileinfo);

	virtual ~CComputerPlayer();
};

#endif /* CCOMPUTERPLAYER_H_ */
