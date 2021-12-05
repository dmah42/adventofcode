#include <fstream>
#include <iostream>

#include "absl/base/macros.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"
#include "floor.h"

XY ParseCoord(absl::string_view s) {
  const std::vector<std::string>& parts = absl::StrSplit(s, ',');
  std::vector<int> ints;
  std::transform(parts.cbegin(), parts.cend(), std::back_inserter(ints),
                 [](const std::string& s) {
                   int v;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &v));
                   return v;
                 });
  ABSL_ASSERT(ints.size() == 2);
  return {.x = ints[0], .y = ints[1]};
}

int main() {
  std::ifstream inf("2021/5/input.txt");

  Floor f{1000, 1000};

  std::string start, arrow, end;
  while (inf >> start >> arrow >> end) {
    ABSL_ASSERT(arrow == "->");
    const XY startXY = ParseCoord(start);
    const XY endXY = ParseCoord(end);

    f.DrawLine(startXY, endXY);
  }

  std::cout << "crossings: " << f.CountGreaterEq(2) << '\n';

  return 0;
}