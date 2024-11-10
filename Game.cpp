#include "Game.h"
#include <iostream>
#include <iomanip>

using namespace std;
Game::Game() {}

void Game::printGameInstructions() {
    cout << setw(30) << "--------2048 game--------" << "\n" <<
        "To achieve victory, reach 2048 on any tile!\n" <<
        "To move the tiles use keys 'w', 'a', 's', 'd' - up, left, down, right.\n" <<
        "To restart the game enter - 'r' or 'R'\n" <<
        "To quit the game enter - q or Q\n\n";
}

void Game::restartGame() {
    board.restartGame();
    system("cls");
    cout << "Game restarted!\n";
    board.printUI();
    cout << "\n";
}

bool Game::continueGameOrQuit() {
    char input;
    while (true) {
        cout << "\nEnter 'Q' to quit or 'R' to restart: ";
        cin >> input;
        if (input == 'q' || input == 'Q') {
            return false;
        }
        if (input == 'r' || input == 'R') {
            return true;
        }
    }
}

void Game::run() {
    printGameInstructions();
    board.printUI();

    char input;
    while (true)
    {
        if (!board.isGameOver()) {
            cout << "\nGAME OVER! No more possible moves!\n";
            cout << "Score: " << board.getScore();
            if (continueGameOrQuit()) {
                restartGame();
                continue;
            }
            else {
                return;
            }
        }
        if (board.isGameWon()) {
            cout << "\YOU WON! 2048 has been cleared!\n";
            cout << "Score: " << board.getScore();
            if (continueGameOrQuit()) {
                restartGame();
                continue;
            }
            else {
                return;
            }
        }
        cin >> input;
        if (input == 'q' || input == 'Q') {
            cout << "Quiting the game...\n";
            return;
        }
        if (input == 'r' || input == 'R') {
            restartGame();
            continue;
        }
        

        bool canMove = board.move(input);
        if (canMove) {
            system("cls");
            board.addTile();
            board.printUI(); cout << "\n";
        }
        else {
            cout << "Invalid move. Try again.\n";
        }
    }
}


