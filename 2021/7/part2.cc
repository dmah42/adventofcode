#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "2021/7/lib.h"
#include "2021/input.h"

int triangular(int n) { return n * (n + 1) / 2; }

int total_fuel(const std::vector<int>& crabs, int pos) {
  int fuel = 0;
  std::for_each(crabs.begin(), crabs.end(),
                [&fuel, pos](int c) { fuel += triangular(std::abs(c - pos)); });
  return fuel;
}

int main() {
  const std::vector<int> crabs = read_ints("2021/7/input.txt");
  //{16, 1, 2, 0, 4, 2, 7, 1, 2, 14};

  const int max = *std::max_element(crabs.begin(), crabs.end());

  int min_fuel = std::numeric_limits<int>::max();
  for (int pos = 0; pos < max; ++pos) {
    min_fuel = std::min(min_fuel, total_fuel(crabs, pos));
  }
  std::cout << min_fuel << '\n';
  return 0;
}