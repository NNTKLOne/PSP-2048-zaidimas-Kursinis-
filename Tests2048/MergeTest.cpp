#include "pch.h"
#include "CppUnitTest.h"
#include "../Board.cpp"
#include "../Board.h"
#include "../MoveUp.cpp"
#include "../MoveUp.h"
#include "../MoveDown.cpp"
#include "../MoveDown.h"
#include "../MoveRight.cpp"
#include "../MoveRight.h"
#include "../MoveLeft.cpp"
#include "../MoveLeft.h"
#include "../Tile.cpp"
#include "../Tile.h"
#include "../MoveStrategy.cpp"
#include "../MoveStrategy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests2048
{
    TEST_CLASS(MergeTest)
    {
    public:

        TEST_METHOD(MergeAdjacentTiles)
        {
            Board board;

            // Two adjacent tiles with the same value { 2 2 0 0 }
            board.setTile(0, 0, 2);
            board.setTile(0, 1, 2);

            MoveLeft moveLeft;
            board.move(moveLeft);

            Assert::AreEqual(board.getTileValue(0, 0), 4, L"Tiles didn't merge");
            Assert::IsTrue(board.isTileEmpty(0, 1), L"Tile value in row 0, column 1 didn't change to 0");
        }
        TEST_METHOD(MergeSeparatedTiles)
        {
            Board board;

            //Two tiles with the same value separated by an empty tile { 2 0 2 0 }
            board.setTile(0, 0, 2);
            board.setTile(0, 2, 2);

            MoveLeft moveLeft;
            board.move(moveLeft);

            Assert::AreEqual(board.getTileValue(0, 0), 4, L"Tiles didn't merge");
            Assert::IsTrue(board.isTileEmpty(0, 2), L"Tile value in row 0, column 2 didn't change to 0");
        }

        
    };
}
