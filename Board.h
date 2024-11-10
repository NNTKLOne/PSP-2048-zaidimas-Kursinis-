#pragma once
#include "Tile.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
class Board {
private:
	vector<vector<Tile>> tiles;
	int score;

	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();

public:
	static const int BOARD_SIZE = 4;
	Board();

	void addTile();
	bool move(char input);

	int getScore() const { return score; }
	
	void printUI();
	bool isGameOver() const;
	bool isGameWon() const;
	void restartGame();

};

