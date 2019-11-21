// Standard (system) header files
#include <iostream>
#include <stdlib.h>
// Add more standard header files as required
// #include <string>
#include "CTicTacToeGame.h"
using namespace std;


// Add your project's header files here
// #include "CFraction.h"

// Main program
int main (void)
{
    // TODO: Add your program code here
	cout << "BoardGame_TicTacToe started." << endl << endl;
	CTicTacToeGame game;
	game.play();
	cout <<endl;
	return 0;
}
