#pragma once
#include "Board.h"

class Game {
private:
    Board board;
    void printGameInstructions() const;
    void restartGame();
    void handleGameOver();
    void handleGameWon();

public:
    Game();
    void run();
};
