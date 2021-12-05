#include "floor.h"

#include <iostream>

bool operator==(const XY& lhs, const XY& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const XY& lhs, const XY& rhs) { return !(lhs == rhs); }

Floor::Floor(int w, int h) {
  _floor.resize(h);
  for (int hh = 0; hh < h; ++hh) {
    _floor[hh].resize(w, 0);
  }
}

int Floor::CountGreaterEq(int min) const {
  int count = 0;
  for (const auto& row : _floor) {
    for (const int value : row) {
      if (value >= min) count++;
    }
  }
  return count;
}

void Floor::DrawLine(XY start, XY end) {
  const XY delta{
      .x = start.x < end.x ? 1 : (start.x > end.x ? -1 : 0),
      .y = start.y < end.y ? 1 : (start.y > end.y ? -1 : 0),
  };

  if (delta.x != 0 && delta.y != 0) {
    std::cout << "diagonal line.. skipping (part1)\n";
    return;
  }

  while (start != end) {
    _floor[start.y][start.x] += 1;

    if (start.x != end.x) start.x += delta.x;
    if (start.y != end.y) start.y += delta.y;
  }
  _floor[end.y][end.x] += 1;
}