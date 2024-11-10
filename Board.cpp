#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board() : tiles(BOARD_SIZE, vector<Tile>(BOARD_SIZE))
{
	this->score = 0;
	srand(static_cast<unsigned int>(time(nullptr)));
	addTile();
	addTile();
}

void Board::restartGame() {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			tiles[row][col].setValue(0);
		}
	}
	score = 0;
	srand(static_cast<unsigned int>(time(nullptr)));
	addTile();
	addTile();
}

bool Board::isGameOver() const {
	Board tempBoard = *this; // creating a copy of Board obj (derefencing this ptr)
	if (tempBoard.move('w')) return true;
	if (tempBoard.move('a')) return true;
	if (tempBoard.move('s')) return true;
	if (tempBoard.move('d')) return true;
	return false;

}
bool Board::isGameWon() const {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (tiles[col][row].getValue() == 2048) {
				return true;
			}
		}
	}
	return false;
}

void Board::addTile() {
	int freeSpace = 1, row, col;
	while (freeSpace)
	{
		row = rand() % 4;
		col = rand() % 4;
		if (tiles[row][col].getValue() == 0) 
			freeSpace = 0;
	}
	if (!freeSpace) {
		int value = (rand() % 100 < 20 ? 4 : 2); // 2 or 4 random gen with odds
		tiles[row][col].setValue(value);
	}
	else
	{
		cout << "Game over! No mo moves are possible!\n";
		return;
	}

}

void Board::printUI() {
	cout << " X---------------------------X\n";
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {

			cout << " | "<<setw(4)<<tiles[row][col].getValue();
		}
		cout << " |\n";
	}
	cout << " X---------------------------X\n";
	cout << "Score: " << score<<"\n";
}

bool Board::move(char input) {
	bool movePossible = false;
	switch (input) {
	case 'w': movePossible = moveUp(); break;
	case 'a': movePossible = moveLeft(); break;
	case 's': movePossible = moveDown(); break;
	case 'd': movePossible = moveRight(); break;
	default: movePossible = false; cout << "Invalid input\n"; break;
	}
	return movePossible;
}

bool Board::moveUp() { // stulpelius judinam // 2 kartus moveUp turetu but tj padaryt reiks cj atskira funkcija
	bool canMoveOrSum = false;
	//moveUp
	for (int col = 0; col < 4; col++) {
		int tempRow = 0;
		for (int row = 0; row < 4; row++) {
			if (tiles[row][col].getValue() != 0) {
				if (row != tempRow) {
					tiles[tempRow][col].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempRow++;
			}
		}
	}
	
	//sumUp
	for (int col = 0; col < 4; col++) {
		for (int row = 0; row < 3; row++) {
			if (tiles[row][col].getValue() != 0) {
				if (tiles[row][col].getValue() == tiles[row+1][col].getValue()) {
					tiles[row][col].setValue(tiles[row][col].getValue() * 2);
					tiles[row+1][col].setValue(0);
					canMoveOrSum = true;
					score += tiles[row][col].getValue()/2;
				}
			}
		}
	}

	//moveUp
	for (int col = 0; col < 4; col++) {
		int tempRow = 0;
		for (int row = 0; row < 4; row++) {
			if (tiles[row][col].getValue() != 0) {
				if (row != tempRow) {
					tiles[tempRow][col].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempRow++;
			}
		}
	}
	return canMoveOrSum;
}

bool Board::moveDown() {
	bool canMoveOrSum = false;
	//moveDown
	for (int col = 0; col < 4; col++) {
		int tempRow = 3;
		for (int row = 3; row > -1; row--) {
			if (tiles[row][col].getValue() != 0) {
				if (row != tempRow) {
					tiles[tempRow][col].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempRow--;
			}
		}
	}

	//sumDown
	for (int col = 0; col < 4; col++) {
		for (int row = 3; row > 0; row--) {
			if (tiles[row][col].getValue() != 0) {
				if (tiles[row][col].getValue() == tiles[row -1][col].getValue()) {
					tiles[row][col].setValue(tiles[row][col].getValue()*2);
					tiles[row-1][col].setValue(0);
					canMoveOrSum = true;
					score += tiles[row][col].getValue()/2;
				}
			}
		}
	}

	//moveDown
	for (int col = 0; col < 4; col++) {
		int tempRow = 3;
		for (int row = 3; row > -1; row--) {
			if (tiles[row][col].getValue() != 0) {
				if (row != tempRow) {
					tiles[tempRow][col].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempRow--;
			}
		}
	}
	return canMoveOrSum;
}

bool Board::moveLeft() {
	bool canMoveOrSum = false;
	//moveLeft
	for (int row = 0; row < 4; row++) {
		int tempCol = 0;
		for (int col = 0; col <4; col++) {
			if (tiles[row][col].getValue() != 0) {
				if (col != tempCol) {
					tiles[row][tempCol].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempCol++;
			}
		}
	}

	//sumLeft
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 3; col++) {
			if (tiles[row][col].getValue() != 0) {
				if (tiles[row][col].getValue() == tiles[row][col+1].getValue()) {
					tiles[row][col].setValue(tiles[row][col].getValue() * 2);
					tiles[row][col + 1].setValue(0);
					canMoveOrSum = true;
					score += tiles[row][col].getValue()/2;
				}
			}
		}
	}

	//moveLeft
	for (int row = 0; row < 4; row++) {
		int tempCol = 0;
		for (int col = 0; col < 4; col++) {
			if (tiles[row][col].getValue() != 0) {
				if (col != tempCol) {
					tiles[row][tempCol].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempCol++;
			}
		}
	}
	return canMoveOrSum;
}

bool Board::moveRight() {
	bool canMoveOrSum = false;
	//moveRight
	for (int row = 0; row < 4; row++) {
		int tempCol = 3;
		for (int col = 3; col > -1; col--) {
			if (tiles[row][col].getValue() != 0) {
				if (col != tempCol) {
					tiles[row][tempCol].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempCol--;
			}
		}
	}

	//sumRight
	for (int row = 0; row < 4; row++) {
		for (int col = 3; col > 0; col--) {
			if (tiles[row][col].getValue() != 0) {
				if (tiles[row][col].getValue() == tiles[row][col - 1].getValue()) {
					tiles[row][col].setValue(tiles[row][col].getValue()*2);
					tiles[row][col-1].setValue(0);
					canMoveOrSum = true;
					score += tiles[row][col].getValue()/2;
				}
			}
		}
	}

	//moveRight
	for (int row = 0; row < 4; row++) {
		int tempCol = 3;
		for (int col = 3; col > -1; col--) {
			if (tiles[row][col].getValue() != 0) {
				if (col != tempCol) {
					tiles[row][tempCol].setValue(tiles[row][col].getValue());
					tiles[row][col].setValue(0);
					canMoveOrSum = true;
				}
				tempCol--;
			}
		}
	}
	return canMoveOrSum;
}
