#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "absl/base/macros.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"

namespace {
constexpr int GENERATIONS = 80;
}

int main() {
  std::ifstream inf("2021/6/input.txt");
  std::string line;
  inf >> line;
  const std::vector<std::string> strs = absl::StrSplit(line, ',');
  std::vector<int> fish;
  std::transform(strs.cbegin(), strs.cend(), std::back_inserter(fish),
                 [](const std::string& s) {
                   int v;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &v));
                   return v;
                 });
  // std::vector<int> fish = {3, 4, 3, 1, 2};

  for (int gen = 0; gen < GENERATIONS; ++gen) {
    int new_fish = 0;
    for (int& f : fish) {
      --f;
      if (f < 0) {
        f = 6;
        ++new_fish;
      }
    }

    for (int i = 0; i < new_fish; ++i) {
      fish.emplace_back(8);
    }
    std::cout << "gen " << gen << ": " << fish.size() << '\n';
  }
}