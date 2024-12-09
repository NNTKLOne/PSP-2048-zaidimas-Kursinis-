#include "MoveStrategy.h"

void MoveStrategy::compactAndMerge(vector<int>& line, int& score) {
    compactNonZeroValues(line);

    // Merge
    for (int i = 0; i < line.size() - 1; ++i) {
        if (line[i] != 0 && line[i] == line[i + 1]) {
            line[i] *= 2;
            score += line[i];
            line[i + 1] = 0;
        }
    }
    compactNonZeroValues(line);
}

void MoveStrategy::compactNonZeroValues(std::vector<int>& line) {
    int tempPos = 0;
    for (int pos = 0; pos < line.size(); ++pos) {
        if (line[pos] != 0) {
            if (pos != tempPos) {
                line[tempPos] = line[pos];
                line[pos] = 0;
            }
            ++tempPos;
        }
    }
}
