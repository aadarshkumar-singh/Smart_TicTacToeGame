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

class CComputerPlayer:public CPlayer
{
	CPosition m_boardSize;
	int m_bestRow;
	int m_bestColumn;
	void findBestMove(BoardState_t tileinfo,BoardState_t **board);
	int checkIfWon(BoardState_t playerTile,BoardState_t **board);
	int checkRowsForWin(BoardState_t playerTile,BoardState_t **board);
	int checkColumnForWin(BoardState_t playerTile,BoardState_t **board);
	int checkPrimaryDiagnolForWin(BoardState_t playerTile,BoardState_t **board);
	int checkSecondaryDiagnolForWin(BoardState_t playerTile,BoardState_t **board);
	int checkIfEmpty(BoardState_t **board);
	int checkIfAttack(BoardState_t playerTile,BoardState_t **board);
	int checkIfBlock(BoardState_t playerTile,BoardState_t **board);
	int checkIfCornerEmpty(BoardState_t playerTile,BoardState_t **board);
	int checkIfOpponentisInCorner(BoardState_t playerTile,BoardState_t **board);
	int checkifSidesEmpty(BoardState_t playerTile,BoardState_t **board);

public:
	CComputerPlayer();
	void placeTile(BoardState_t tileinfo,BoardState_t **board);

	virtual ~CComputerPlayer();
};

#endif /* CCOMPUTERPLAYER_H_ */
