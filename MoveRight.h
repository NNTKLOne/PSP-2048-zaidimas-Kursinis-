#pragma once
#include "MoveStrategy.h"

class MoveRight : public MoveStrategy {
public:
    bool executeMove(vector<vector<Tile>>& tiles, int& score) override;
};
