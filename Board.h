#pragma once
#include "Tile.h"
#include "MoveStrategy.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Board {
private:
    vector<vector<Tile>> tiles;
    int score;

    static const int BOARD_SIZE = 4;
    static const int WIN_TILE = 2048;

public:
    Board(); 
    void restartGame();
    void addTile();
    bool move(MoveStrategy& strategy); // Polymorphism - Accepts any MoveStrategy.
    void printUI() const;
    bool isGameOver() const;
    bool isGameWon() const;

    int getScore() const { return score; }
    // For unit tests
    int getTileValue(int row, int col) const { return tiles[row][col].getValue(); }
    bool isTileEmpty(int row, int col) const { return tiles[row][col].isEmpty(); }
    void setTile(int row, int col, int value);
};

