#include <algorithm>
#include <iostream>
#include <vector>

#include "2021/input.h"
#include "lib.h"

int main() {
  const std::vector<int> crabs = read_ints("2021/7/input.txt");
  // {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};

  int m = median(crabs);
  int fuel = 0;
  std::for_each(crabs.begin(), crabs.end(),
                [&fuel, m](int c) { fuel += std::abs(c - m); });
  std::cout << fuel << '\n';
  return 0;
}