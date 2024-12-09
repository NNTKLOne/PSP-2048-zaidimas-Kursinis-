#pragma once
#include "MoveStrategy.h"

class MoveLeft : public MoveStrategy {
public:
    bool executeMove(vector<vector<Tile>>& tiles, int& score) override;
};
