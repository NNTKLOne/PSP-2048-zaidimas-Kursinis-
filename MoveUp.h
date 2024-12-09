#pragma once
#include "MoveStrategy.h"

class MoveUp : public MoveStrategy {
public:
    bool executeMove(vector<vector<Tile>>& tiles, int& score) override;
};
