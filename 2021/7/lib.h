#include <vector>

#include "absl/strings/string_view.h"

std::vector<int> read_ints(absl::string_view file);

int median(std::vector<int> v);
int mean(const std::vector<int>& v);