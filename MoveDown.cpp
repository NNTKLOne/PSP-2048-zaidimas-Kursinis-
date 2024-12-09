#include "MoveDown.h"

bool MoveDown::executeMove(vector<vector<Tile>>& tiles, int& score) {
    bool moved = false;
    for (size_t col = 0; col < tiles.size(); ++col) {
        vector<int> column;
        for (size_t row = tiles.size(); row > 0; --row) {
            column.push_back(tiles[row - 1][col].getValue()); // Save line in reverse
        }

        vector<int> original = column;
        compactAndMerge(column, score);

        for (size_t row = tiles.size(), i = 0; row > 0; --row, ++i) {
            tiles[row - 1][col].setValue(column[i]);
        }

        if (column != original) moved = true;
    }
    return moved;
}

