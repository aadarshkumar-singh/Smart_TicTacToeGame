/***************************************************************************
****************************************************************************
 * \file CTicTacToeBoard.cpp
 * \author Aadarsh Kumar Singh <aadarsh.k.singh@stud.h-da.de>
 * \date 17.11.2019
 *
 * \brief CTicTacToeBoard.cpp
 *
 * Source file for the Class CTicTacToeBoard that has methods to create the
 * TicTacToe Board, Create players for the TicTacToe Board based on the user
 * selection of players,create a screen for displaying the board and the
 * result of the game.
 *
 * \note The supported players are humans and computer, and screen is console
 *       view screen.
 *
****************************************************************************/

#include "CTicTacToeBoard.h"
#include "CPosition.h"
#include "iostream"

using namespace std;

/*
 * Initializes the generic board to  a 3x3 TicTacToe Board,
 * creates a console view screen and create players based on user selection
 */
CTicTacToeBoard::CTicTacToeBoard():CBoard(TICTACTOE_ROW_SIZE,TICTACTOE_COLUMN_SIZE)
{
	m_screen = new CTicTacToeConsoleView(m_pBoard,TICTACTOE_ROW_SIZE,TICTACTOE_COLUMN_SIZE);
	createSelectedPlayers();
}

/*
 * Creates Player 1 and Player 2 based on user selection
 */
void CTicTacToeBoard::createSelectedPlayers()
{
	createPlayer1();
	createPLayer2();
}

/*
 * Creates Player 1 (Human/Computer)based on user input
 */
void CTicTacToeBoard::createPlayer1()
{
	if (selectBoardPlayers(PLAYER1) == HUMAN_PLAYER)
	{
		m_player1 = new CHumanPlayer(m_pBoard) ;
		cout <<"Human Player Selected as Player 1"<<endl;
	}
	else
	{
		m_player1 = new CComputerPlayer(m_pBoard) ;
		cout <<"Computer Player Selected as Player 2"<<endl;
	}

}

/*
 * Creates Player 2 (Human/Computer)based on user input
 */
void CTicTacToeBoard::createPLayer2()
{
	if (selectBoardPlayers(PLAYER2)== HUMAN_PLAYER)
	{
		m_player2 = new CHumanPlayer(m_pBoard) ;
		cout <<"Human Player Selected as Player 2"<<endl;
	}
	else
	{
		m_player2 = new CComputerPlayer(m_pBoard) ;
		cout <<"Computer Player Selected as Player 2"<<endl;
	}
}

/*
 * Returns address of the player1 of type CPlayer
 */
CPlayer* CTicTacToeBoard::getBoardPlayer1()
{
	return m_player1;
}

/*
 * Returns address of the player2 of type CPlayer
 */
CPlayer* CTicTacToeBoard::getBoardPlayer2()
{
	return m_player2;
}

/*
 * Returns a double pointer that points to tictactoe board of type BoardState_t
 */
BoardState_t** CTicTacToeBoard::getTicTacToeBoard()
{
	return (m_pBoard);
}

/*
 * Select the players of the tictactoe board based on user inputs
 */
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

/*
 * Displays the Board of tictactoe game
 */
void CTicTacToeBoard::displayBoard()
{
	m_screen->printBoard();
}

/*
 * Displays the Result of the tictactoe game
 */
void CTicTacToeBoard::displayResult(gamePlayers_t Player, BoardState_t winTile , gameResult_t result)
{
	displayBoard();
	m_screen->printResult(Player,winTile,result);
}

/*
 * Frees the screen , player 1 and player 2 memory
 */
CTicTacToeBoard::~CTicTacToeBoard()
{
	delete[] m_screen;
	delete[] m_player1;
	delete[] m_player2;
}
