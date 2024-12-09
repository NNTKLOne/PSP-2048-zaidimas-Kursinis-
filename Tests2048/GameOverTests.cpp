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
	TEST_CLASS(GameOverTests)
	{
	public:
		
		TEST_METHOD(GameIsOver)
		{
			Board board;

			// Fill the board with non-merging values
			for (int row = 0; row < 4; ++row) {
				for (int col = 0; col < 4; ++col) {
					board.setTile(row, col, row * 4 + col + 1);
				}
			}

			Assert::IsTrue(board.isGameOver());
		}
		TEST_METHOD(GameIsNotOver)
		{
			Board board;

			// Fill the board with non-merging values
			for (int row = 0; row < 4; ++row) {
				for (int col = 0; col < 4; ++col) {
					board.setTile(row, col, 2);
				}
			}

			Assert::IsFalse(board.isGameOver());
		}

	};
}
