/*
 * CTicTacToeBoard.h
 *
 *  Created on: Nov 17, 2019
 *      Author: Aadarshxp
 */

#ifndef CTICTACTOEBOARD_H_
#define CTICTACTOEBOARD_H_

#include "CBoard.h"
#include "CTicTacToeConsoleView.h"
#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"

/**
 * \brief Number of rows of the tictactoe board
 */
#define TICTACTOE_ROW_SIZE 3

/**
 * \brief Number of Columns of the tictactoe board
 */
#define TICTACTOE_COLUMN_SIZE 3

enum TicTacToeGui_e
{
	CONSOLEVIEWAPPLICATION,
	GRAPHICAL_FORMAT
};

class CTicTacToeBoard : public CBoard
{
	CScreen *m_screen;
	CPlayer *m_player1;
	CPlayer *m_player2;

	playerInfo_t selectBoardPlayers(gamePlayers_t index);
	void createSelectedPlayers();
	void createPlayer1();
	void createPLayer2();


public:
	CTicTacToeBoard();
	void displayBoard();
	CPlayer* getBoardPlayer1();
	CPlayer* getBoardPlayer2();
	BoardState_t** getTicTacToeBoard();


	virtual ~CTicTacToeBoard();
};

#endif /* CTICTACTOEBOARD_H_ */
