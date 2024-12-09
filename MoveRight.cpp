#include "MoveRight.h"

bool MoveRight::executeMove(vector<vector<Tile>>& tiles, int& score) {
    bool moved = false;
    for (auto& row : tiles) {
        vector<int> line;
        for (auto it = row.rbegin(); it != row.rend(); ++it) {
            line.push_back(it->getValue()); // Save the line in reverse
        }

        vector<int> original = line;
        compactAndMerge(line, score);

        for (size_t i = 0, j = row.size() - 1; i < line.size(); ++i, --j) {
            row[j].setValue(line[i]);
        }

        if (line != original) moved = true;
    }
    return moved;
}
