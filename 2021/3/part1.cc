#include <array>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream inf("2021/3/input.txt");

  std::array<int, 12> count_ones;
  std::array<int, 12> count_zeros;

  for (int i = 0; i < count_ones.size(); ++i) {
    count_ones[i] = 0;
    count_zeros[i] = 0;
  }

  std::string s;
  while (inf >> s) {
    assert(s.size() == count_ones.size());
    assert(s.size() == count_zeros.size());
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        count_ones[i]++;
      } else if (s[i] == '0') {
        count_zeros[i]++;
      } else {
        std::cerr << "unexpected bit\n";
        return 1;
      }
    }
  }

  int gamma = 0, epsilon = 0;
  for (int i = 0; i < count_ones.size(); ++i) {
    if (count_ones[i] > count_zeros[i]) {
      gamma |= 1 << (count_ones.size() - i - 1);
    } else if (count_ones[i] < count_zeros[i]) {
      epsilon |= 1 << (count_ones.size() - i - 1);
    } else {
      std::cerr << "unexpected equality\n";
      return 1;
    }
  }

  std::cout << "gamma: " << gamma << '\n';
  std::cout << "epsilon: " << epsilon << '\n';
  std::cout << "power: " << gamma * epsilon << '\n';
  return 0;
}