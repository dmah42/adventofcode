#include <algorithm>
#include <functional>
#include <vector>

int median(std::vector<int> v) {
  auto n = v.size() / 2;
  std::nth_element(v.begin(), v.begin() + n, v.end());
  return v[n];
}