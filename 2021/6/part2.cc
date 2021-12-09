#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "absl/base/macros.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"

namespace {
constexpr int GENERATIONS = 256;

void run(const std::string& file) {
  std::cout << file << '\n';
  std::ifstream inf(file);
  std::string line;
  inf >> line;
  const std::vector<std::string> strs = absl::StrSplit(line, ',');
  std::vector<int> timers;
  std::transform(strs.cbegin(), strs.cend(), std::back_inserter(timers),
                 [](const std::string& s) {
                   int timer = 0;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &timer));
                   return timer;
                 });

  // maps from timer to population at that timer.
  auto fish = std::unordered_map<int, uint64_t>{
      {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0},
  };
  for (const int t : timers) {
    ++fish[t];
  }

  for (int gen = 0; gen < GENERATIONS; ++gen) {
    uint64_t new_fish = fish[0];
    fish[0] = fish[1];
    fish[1] = fish[2];
    fish[2] = fish[3];
    fish[3] = fish[4];
    fish[4] = fish[5];
    fish[5] = fish[6];
    fish[6] = fish[7];
    fish[7] = fish[8];
    // spawn!
    fish[6] += new_fish;
    fish[8] = new_fish;
    std::cout << '.';
  }
  std::cout << '\n';

  uint64_t total_fish = 0U;
  for (const auto& f : fish) {
    total_fish += f.second;
  }
  std::cout << GENERATIONS << '\t' << total_fish << '\n';
}
}  // namespace

int main() {
  run("2021/6/test.txt");
  run("2021/6/input.txt");
}
