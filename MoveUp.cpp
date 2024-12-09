#include "MoveUp.h"

bool MoveUp::executeMove(vector<vector<Tile>>& tiles, int& score) {
    bool moved = false;
    for (size_t col = 0; col < tiles.size(); ++col) {
        vector<int> column;
        for (size_t row = 0; row < tiles.size(); ++row) {
            column.push_back(tiles[row][col].getValue());
        }

        vector<int> original = column;
        compactAndMerge(column, score);

        for (size_t row = 0; row < tiles.size(); ++row) {
            tiles[row][col].setValue(column[row]);
        }

        if (column != original) moved = true;
    }
    return moved;
}

