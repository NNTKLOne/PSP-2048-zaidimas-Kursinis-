#pragma once
#include "MoveStrategy.h"

class MoveDown : public MoveStrategy {
public:
    bool executeMove(vector<vector<Tile>>& tiles, int& score) override;
};
