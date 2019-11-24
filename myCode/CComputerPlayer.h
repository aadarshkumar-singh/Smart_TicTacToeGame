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
	CENTER,
	CORNER,
	EDGE,
	ATTACKORDEFEND,
	OPPOSITECORNER,
};
typedef playerMoves_e playerMoves_t ;

class CComputerPlayer:public CPlayer
{
	CPosition m_boardSize;
	BoardState_t **m_playerBoard;
	int m_bestRow;
	int m_bestColumn;

	void findBestMove(BoardState_t tileinfo);
	int checkIfWon(BoardState_t playerTile);
	int checkRowsOrColumnForWin(BoardState_t playerTile);
	int checkDiagnolsForWin(BoardState_t playerTile);
	int checkToAttackBlockOrPlace(BoardState_t playerTile,playerMoves_t checkMove);
	int checkIfOpponentisInCorner(BoardState_t playerTile);
	int blockFork(BoardState_t playerTile);

public:
	CComputerPlayer();
	CComputerPlayer(BoardState_t **pboard);
	void placeTile(BoardState_t tileinfo);

	virtual ~CComputerPlayer();
};

#endif /* CCOMPUTERPLAYER_H_ */
