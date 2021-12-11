#include <algorithm>
#include <fstream>
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