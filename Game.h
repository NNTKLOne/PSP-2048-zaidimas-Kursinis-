#pragma once
#include "Board.h"
#include <iostream>
class Game {
private:
	Board board;
	void printGameInstructions();
	void restartGame();
	bool continueGameOrQuit();

public:
	Game();
	void run();
};

