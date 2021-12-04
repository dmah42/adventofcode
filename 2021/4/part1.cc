#include <fstream>
#include <iostream>
#include <vector>

#include "absl/base/macros.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_join.h"
#include "absl/strings/str_split.h"
#include "board.h"

namespace {
constexpr char input[] = "2021/4/input.txt";

std::vector<int> parseDrawn() {
  std::ifstream inf(input);
  std::string line;
  inf >> line;
  const std::vector<std::string> strs = absl::StrSplit(line, ',');
  std::vector<int> ints;
  std::transform(strs.cbegin(), strs.cend(), std::back_inserter(ints),
                 [](const std::string& s) {
                   int v;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &v));
                   return v;
                 });
  return ints;
}

std::vector<Board> parseBoards() {
  std::ifstream inf(input);
  // skip drawn line
  std::string line;
  inf >> line;

  std::vector<Board> boards;

  while (!inf.eof()) {
    bool set = false;
    Board b;
    // assume batches of five
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        std::string cell;
        inf >> cell;
        if (cell.empty()) continue;
        int value;
        ABSL_ASSERT(absl::SimpleAtoi(cell, &value));
        set = true;
        b.Set(i, j, value);
      }
    }
    if (set) boards.emplace_back(b);
  }

  return boards;
}

}  // namespace

int main() {
  std::vector<int> drawn = parseDrawn();
  std::vector<Board> boards = parseBoards();

  std::cout << "drawn: " << absl::StrJoin(drawn, ", ") << '\n';
  std::cout << "boards:\n";
  for (const auto& b : boards) {
    std::cout << b.ToString() << '\n';
  }

  for (const int draw : drawn) {
    for (auto& b : boards) {
      b.Mark(draw);

      if (b.Winner()) {
        std::cout << b.Score(draw) << '\n';
        return 0;
      }
    }
  }
  std::cerr << "no winner\n";
  return 1;
}