#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
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
  std::vector<int> ints;
  std::transform(strs.cbegin(), strs.cend(), std::back_inserter(ints),
                 [](const std::string& s) {
                   int v = 0;
                   ABSL_ASSERT(absl::SimpleAtoi(s, &v));
                   return v;
                 });
  return ints;
}

int median(std::vector<int> v) {
  auto n = v.size() / 2;
  std::nth_element(v.begin(), v.begin() + n, v.end());
  return v[n];
}

int mean(const std::vector<int>& v) {
  int total = 0;
  std::for_each(v.begin(), v.end(), [&total](int n) { total += n; });
  return total / v.size();
}