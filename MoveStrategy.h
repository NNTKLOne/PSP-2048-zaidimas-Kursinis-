#pragma once
#include "Tile.h"
#include <vector>

// Abstract interface for movement strategies
class MoveStrategy {
public:
    virtual bool executeMove(vector<vector<Tile>>& tiles, int& score) = 0;
    virtual ~MoveStrategy() = default;

protected:
    void compactAndMerge(vector<int>& line, int& score);
    void compactNonZeroValues(std::vector<int>& line);
};
