#include "floor.h"

#include "gtest/gtest.h"

TEST(FloorTest, DrawLine_Horizontal) {
  auto f = Floor(3, 3);
  f.DrawLine({0, 2}, {1, 2});
  EXPECT_EQ(f.Get({0, 0}), 0);
  EXPECT_EQ(f.Get({0, 1}), 0);
  EXPECT_EQ(f.Get({0, 2}), 1);
  EXPECT_EQ(f.Get({1, 0}), 0);
  EXPECT_EQ(f.Get({1, 1}), 0);
  EXPECT_EQ(f.Get({1, 2}), 1);
  EXPECT_EQ(f.Get({2, 0}), 0);
  EXPECT_EQ(f.Get({2, 1}), 0);
  EXPECT_EQ(f.Get({2, 2}), 0);
}

TEST(FloorTest, DrawLine_Vertical) {
  auto f = Floor(3, 3);
  f.DrawLine({1, 0}, {1, 1});
  EXPECT_EQ(f.Get({0, 0}), 0);
  EXPECT_EQ(f.Get({0, 1}), 0);
  EXPECT_EQ(f.Get({0, 2}), 0);
  EXPECT_EQ(f.Get({1, 0}), 1);
  EXPECT_EQ(f.Get({1, 1}), 1);
  EXPECT_EQ(f.Get({1, 2}), 0);
  EXPECT_EQ(f.Get({2, 0}), 0);
  EXPECT_EQ(f.Get({2, 1}), 0);
  EXPECT_EQ(f.Get({2, 2}), 0);
}

TEST(FloorTest, Part1) {
  auto f = Floor(10, 10);
  f.DrawLine({0, 9}, {5, 9});
  f.DrawLine({8, 0}, {0, 8});
  f.DrawLine({9, 4}, {3, 4});
  f.DrawLine({2, 2}, {2, 1});
  f.DrawLine({7, 0}, {7, 4});
  f.DrawLine({6, 4}, {2, 0});
  f.DrawLine({0, 9}, {2, 9});
  f.DrawLine({3, 4}, {1, 4});
  f.DrawLine({0, 0}, {8, 8});
  f.DrawLine({5, 5}, {8, 2});

  EXPECT_EQ(f.CountGreaterEq(2), 5);
}