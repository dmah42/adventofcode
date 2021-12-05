#pragma once

#include <vector>

struct XY {
  int x, y;
};

class Floor {
 public:
  explicit Floor(int w, int h);

  int Get(XY pos) const { return _floor[pos.y][pos.x]; }

  int CountGreaterEq(int min) const;

  void DrawLine(XY start, XY end);

 private:
  std::vector<std::vector<int>> _floor;
};