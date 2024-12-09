#include "Game.h"
#include "MoveUp.h"
#include "MoveDown.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include <iostream>

using namespace std;

Game::Game() {}

void Game::printGameInstructions() const {
    cout << setw(30) << "--------2048 game--------" << "\n" <<
        "To achieve victory, reach 2048 on any tile!\n" <<
        "To move the tiles use keys 'w', 'a', 's', 'd' - up, left, down, right.\n" <<
        "To restart the game enter - 'r' or 'R'\n" <<
        "To quit the game enter - q or Q\n\n";
}

void Game::restartGame() {
    board.restartGame();
    cout << "Game restarted!\n";
    board.printUI();
}

void Game::handleGameOver() {
    cout << "\nGAME OVER! No more possible moves!\n";
    cout << "Final Score: " << board.getScore() << "\n";

    char choice;
    cout << "Enter 'r' to restart or 'q' to quit: ";
    cin >> choice;
    if (choice == 'r' || choice == 'R') {
        restartGame();
    }
    else {
        cout << "Exiting the game...\n";
        exit(0);
    }
}

void Game::handleGameWon() {
    cout << "\nYOU WON! 2048 has been cleared!\n";
    cout << "Score: " << board.getScore() << "\n";
    cout << "Exiting the game...\n";
    exit(0);
}

void Game::run() {
    printGameInstructions();
    board.addTile();
    board.addTile();
    board.printUI();

    char input;
    while (true) {
        if (board.isGameOver()) {
            handleGameOver();
            continue;
        }
        if (board.isGameWon()) {
            handleGameWon();
        }
        cin >> input;

        MoveStrategy* strategy = nullptr;
        if (input == 'q' || input == 'Q') { cout << "Quiting the game...\n"; break; }
        if (input == 'r' || input == 'R') { restartGame(); continue; }
        if (input == 'w') strategy = new MoveUp();
        if (input == 's') strategy = new MoveDown();
        if (input == 'a') strategy = new MoveLeft();
        if (input == 'd') strategy = new MoveRight();

        if (strategy && board.move(*strategy)) { // Polymorphism: Derived class object accessed through base class pointer
            board.addTile();
            board.printUI();
        }
        else {
            cout << "Invalid move. Try again.\n";
        }
        delete strategy;
    }
}
