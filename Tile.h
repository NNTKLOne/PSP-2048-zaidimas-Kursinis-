#pragma once
using namespace std;

class Tile {
private:
    int value;

public:
    Tile(int value = 0);
    int getValue() const;
    void setValue(int value);
    bool isEmpty() const;
};
