#include <fstream>
#include <iostream>
#include <vector>

#include "absl/base/macros.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"

std::vector<int> read_ints(absl::string_view file) {
  std::ifstream inf(std::string{file});
  std::string line;
  inf >> line;
  const std::vector<std::string> strs = absl::StrSplit(line, ',');
  std::vector<int> crabs;
  std::transform(strs.cbegin(), strs.cend(), std::back_inserter(crabs),
                 [](const std::string& s) {
                   int v = 0;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &v));
                   return v;
                 });
  // crabs = {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
  return crabs;
}

int median(std::vector<int> v) {
  auto n = v.size() / 2;
  std::nth_element(v.begin(), v.begin() + n, v.end());
  return v[n];
}

int main() {
  const std::vector<int> crabs = read_ints("2021/7/input.txt");

  int m = median(crabs);
  int fuel = 0;
  std::for_each(crabs.begin(), crabs.end(),
                [&fuel, m](int c) { fuel += std::abs(c - m); });
  std::cout << fuel << '\n';
  return 0;
}