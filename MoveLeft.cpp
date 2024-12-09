#include "MoveLeft.h"

bool MoveLeft::executeMove(vector<vector<Tile>>& tiles, int& score) {
    bool moved = false;
    for (auto& row : tiles) {
        vector<int> line;
        for (auto& tile : row) {
            line.push_back(tile.getValue());
        }

        vector<int> original = line;
        compactAndMerge(line, score);

        for (size_t i = 0; i < row.size(); ++i) {
            row[i].setValue(line[i]);
        }

        if (line != original) moved = true;
    }
    return moved;
}
