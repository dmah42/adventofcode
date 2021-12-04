#include "board.h"

#include "gtest/gtest.h"

namespace {
Board CreateTestBoard() {
  Board b;
  b.Set(0, 0, 14);
  b.Set(0, 1, 21);
  b.Set(0, 2, 17);
  b.Set(0, 3, 24);
  b.Set(0, 4, 4);
  b.Set(1, 0, 10);
  b.Set(1, 1, 16);
  b.Set(1, 2, 15);
  b.Set(1, 3, 9);
  b.Set(1, 4, 19);
  b.Set(2, 0, 18);
  b.Set(2, 1, 8);
  b.Set(2, 2, 23);
  b.Set(2, 3, 26);
  b.Set(2, 4, 20);
  b.Set(3, 0, 22);
  b.Set(3, 1, 11);
  b.Set(3, 2, 13);
  b.Set(3, 3, 6);
  b.Set(3, 4, 5);
  b.Set(4, 0, 2);
  b.Set(4, 1, 0);
  b.Set(4, 2, 12);
  b.Set(4, 3, 3);
  b.Set(4, 4, 7);
  return b;
}
}  // namespace

TEST(BoardTest, winner) {
  Board b = CreateTestBoard();
  b.Mark(7);
  b.Mark(4);
  b.Mark(9);
  b.Mark(5);
  b.Mark(11);

  EXPECT_FALSE(b.Winner());

  b.Mark(17);
  b.Mark(23);
  b.Mark(2);
  b.Mark(0);
  b.Mark(14);
  b.Mark(21);

  EXPECT_FALSE(b.Winner());

  b.Mark(24);

  EXPECT_TRUE(b.Winner());
  EXPECT_EQ(b.Score(24), 4512);
}

TEST(BoardTest, Transpose) {
  Board b = CreateTestBoard().Transpose();
  EXPECT_EQ(b.Get(0, 0), 14);
  EXPECT_EQ(b.Get(0, 1), 10);
  EXPECT_EQ(b.Get(2, 0), 17);
}
