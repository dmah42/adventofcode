#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "absl/base/macros.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"

namespace {
constexpr int GENERATIONS = 80;
}  // namespace

int main() {
  std::ifstream inf("2021/6/input.txt");
  std::string line;
  inf >> line;
  const std::vector<std::string> strs = absl::StrSplit(line, ',');
  std::vector<int64_t> fish;
  std::transform(strs.cbegin(), strs.cend(), std::back_inserter(fish),
                 [](const std::string& s) {
                   int v = 0;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &v));
                   return v;
                 });
  // std::vector<int> fish = {3, 4, 3, 1, 2};

  std::cout << "gen\tnum_fish\n";
  for (int gen = 0; gen < GENERATIONS; ++gen) {
    int new_fish = 0;
    for (auto& f : fish) {
      if (--f < 0) {
        f = 6;
        ++new_fish;
      }
    }

    for (int i = 0; i < new_fish; ++i) {
      fish.emplace_back(8);
    }
    if (gen % 10 == 0) {
      std::cout << gen << '\t' << fish.size() << '\n';
    }
  }
  std::cout << GENERATIONS - 1 << '\t' << fish.size() << '\n';
}