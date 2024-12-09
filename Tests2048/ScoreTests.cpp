#include "pch.h"
#include "CppUnitTest.h"
#include "../Board.h"
#include "../MoveUp.h"
#include "../MoveDown.h"
#include "../MoveRight.h"
#include "../MoveLeft.h"
#include "../Tile.h"
#include "../MoveStrategy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests2048
{
    TEST_CLASS(ScoreTests)
    {
    public:

        TEST_METHOD(ScoreRemainsZeroIfNoMerge)
        {
            Board board;

            board.setTile(0, 0, 2);
            board.setTile(1, 0, 4);

            MoveUp moveUp;
            board.move(moveUp);

            Assert::AreEqual(board.getScore(), 0, L"The score is not zero after merge.");
        }

        TEST_METHOD(ScoreIncreasesOnMerge)
        {
            Board board;

            board.setTile(0, 0, 2);
            board.setTile(1, 0, 2);

            MoveUp moveUp;
            board.move(moveUp);

            Assert::AreEqual(board.getScore(), 4, L"The score is zero after merge.");
        }
    };
}
