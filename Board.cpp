#include "Board.h"
#include <cstdlib>
#include <ctime>
#include "MoveUp.h"
#include "MoveDown.h"
#include "MoveRight.h"
#include "MoveLeft.h"

Board::Board() : tiles(BOARD_SIZE, vector<Tile>(BOARD_SIZE)), score(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Board::restartGame() {
    for (auto& row : tiles) {
        for (auto& tile : row) {
            tile.setValue(0);
        }
    }
    score = 0;
    addTile();
    addTile();
}

void Board::addTile() {
    vector<pair<int, int>> emptyPositions;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (tiles[row][col].isEmpty()) {
                emptyPositions.emplace_back(row, col);
            }
        }
    }
    if (!emptyPositions.empty()) {
        pair<int, int> position = emptyPositions[rand() % emptyPositions.size()];
        int row = position.first;
        int col = position.second;
        tiles[row][col].setValue(rand() % 100 < 20 ? 4 : 2);
  /*      setTile(row, col, rand() % 100 < 20 ? 4 : 2);*/
    }
}

bool Board::move(MoveStrategy& strategy) {
    return strategy.executeMove(tiles, score);
}

void Board::printUI() const {
    cout << " X---------------------------X\n";
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            cout << " | " << setw(4) << tile.getValue();
        }
        cout << " |\n";
    }
    cout << " X---------------------------X\n";
    cout << "Score: " << score << "\n";
}

bool Board::isGameOver() const {
    Board tempBoard = *this; // Create a copy of current board obj
    MoveUp moveUp;
    MoveDown moveDown;
    MoveLeft moveLeft;
    MoveRight moveRight;

    if (tempBoard.move(moveUp)) return false;
    if (tempBoard.move(moveDown)) return false;
    if (tempBoard.move(moveLeft)) return false;
    if (tempBoard.move(moveRight)) return false;

    return true;
}

bool Board::isGameWon() const {
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            if (tile.getValue() == WIN_TILE) return true;
        }
    }
    return false;
}

void Board::setTile(int row, int col, int value) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        tiles[row][col].setValue(value);
    }
    else {
        throw std::out_of_range("Row or column index out of bounds");
    }
}
