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
	SIDE
};
typedef playerMoves_e playerMoves_t ;

class CComputerPlayer:public CPlayer
{
	CPosition m_boardSize;
	int m_bestRow;
	int m_bestColumn;
	void findBestMove(BoardState_t tileinfo,BoardState_t **board);
	int checkIfWon(BoardState_t playerTile,BoardState_t **board);
	int checkRowsOrColumnForWin(BoardState_t playerTile,BoardState_t **board);
	int checkDiagnolsForWin(BoardState_t playerTile,BoardState_t **board);
	int checkIfEmpty(BoardState_t **board);
	int checkIfAttackOrBlock(BoardState_t playerTile,BoardState_t **board);
	int checkIfCornerOrSideEmpty(BoardState_t playerTile,BoardState_t **board,playerMoves_t checkMove);
	int checkIfOpponentisInCorner(BoardState_t playerTile,BoardState_t **board);

public:
	CComputerPlayer();
	void placeTile(BoardState_t tileinfo,BoardState_t **board);

	virtual ~CComputerPlayer();
};

#endif /* CCOMPUTERPLAYER_H_ */
