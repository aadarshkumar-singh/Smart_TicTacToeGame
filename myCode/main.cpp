// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "CTicTacToeGame.h"

using namespace std;

// Main program
int main (void)
{
    cout << " TicTacToe Board Game started." << endl << endl;
    /*
     * Seed for random number generation
     * Random Number is used to randomize only the initial moves
     * of the computer otherwise computer always will start from
     * one particular position, hence out of 5 moves that has maximum
     * Probability of winning we choose 1
     */
	srand (time(NULL));
	/*
	 * Object of the TicTacToe Game created
	 */
	CTicTacToeGame game;

	/*
	 * TicTacToeGame Started
	 */
	game.play();

	cout <<endl;
	return 0;
}
