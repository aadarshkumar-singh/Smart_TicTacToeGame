/*
 * CTicTacToeBoard.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: Aadarshxp
 */

#include "CTicTacToeBoard.h"
#include "CPosition.h"
#include "iostream"

using namespace std;

CTicTacToeBoard::CTicTacToeBoard():CBoard(TICTACTOE_ROW_SIZE,TICTACTOE_COLUMN_SIZE)
{
	m_screen = new CTicTacToeConsoleView(m_pBoard);
	createSelectedPlayers();
}

void CTicTacToeBoard::createSelectedPlayers()
{
	createPlayer1();
	createPLayer2();
}

void CTicTacToeBoard::createPlayer1()
{
	if (selectBoardPlayers(PLAYER1) == HUMAN_PLAYER)
	{
		m_player1 = new CHumanPlayer ;
	}
	else
	{
		m_player1 = new CComputerPlayer ;
	}

}

void CTicTacToeBoard::createPLayer2()
{
	if (selectBoardPlayers(PLAYER2)== HUMAN_PLAYER)
	{
		m_player2 = new CHumanPlayer ;
	}
	else
	{
		m_player2 = new CComputerPlayer ;
	}
}

CPlayer* CTicTacToeBoard::getBoardPlayer1()
{
	return m_player1;
}

CPlayer* CTicTacToeBoard::getBoardPlayer2()
{
	return m_player2;
}

BoardState_t** CTicTacToeBoard::getTicTacToeBoard()
{
	return (m_pBoard);
}

playerInfo_t CTicTacToeBoard::selectBoardPlayers(gamePlayers_t index)
{
	int player;

	while(1)
	{
		cout<<"Select player: "<<index<<" (0 - human, 1 - computer)"<<endl;
		cin>>player;

		if (player != HUMAN_PLAYER && player != COMPUTER_PLAYER)
		{
			cout <<"Invalid Input , Enter player detail again" <<endl;
		}
		else
		{
			break;
		}
	}

	return((playerInfo_t)player);
}


CTicTacToeBoard::~CTicTacToeBoard()
{
	// TODO Auto-generated destructor stub
}

void CTicTacToeBoard::displayBoard()
{
	m_screen->printScreen(CPosition::m_rowCount,CPosition::m_columnCount);
}

void CTicTacToeBoard::displayResult(gamePlayers_t Player, BoardState_t winTile , gameResult_t result)
{
	displayBoard();
	m_screen->printResult(Player,winTile,result);
}

