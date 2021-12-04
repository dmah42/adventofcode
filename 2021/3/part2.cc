#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void count(const std::vector<std::string>& input, int i, int& ones,
           int& zeros) {
  ones = 0;
  zeros = 0;
  for (const auto& s : input) {
    if (s[i] == '1') {
      ones++;
    } else if (s[i] == '0') {
      zeros++;
    } else {
      std::cerr << "unexpected bit\n";
    }
  }
}

std::string getOxy(std::vector<std::string> input) {
  for (int i = 0; i < input[0].size(); ++i) {
    int count_ones = 0;
    int count_zeros = 0;

    count(input, i, count_ones, count_zeros);

    int common = count_ones >= count_zeros ? '1' : '0';

    std::vector<std::string> filtered;
    std::copy_if(input.begin(), input.end(), std::back_inserter(filtered),
                 [i, common](std::string s) { return s[i] == common; });
    if (filtered.size() == 1) {
      return filtered[0];
    }
    input = filtered;
  }
  return "failed to find oxy";
}

std::string getCO2(std::vector<std::string> input) {
  for (int i = 0; i < input[0].size(); ++i) {
    int count_ones = 0;
    int count_zeros = 0;

    count(input, i, count_ones, count_zeros);

    int common = count_ones < count_zeros ? '1' : '0';

    std::vector<std::string> filtered;
    std::copy_if(input.begin(), input.end(), std::back_inserter(filtered),
                 [i, common](std::string s) { return s[i] == common; });
    if (filtered.size() == 1) {
      return filtered[0];
    }
    input = filtered;
  }
  return "failed to find co2";
}

int main() {
  std::ifstream inf("2021/3/input.txt");

  std::vector<std::string> input;

  std::string s;
  while (inf >> s) {
    input.emplace_back(s);
  }

  const int oxy = std::stoull(getOxy(input), nullptr, 2);
  const int co2 = std::stoull(getCO2(input), nullptr, 2);

  std::cout << "oxy: " << oxy << '\n';
  std::cout << "co2: " << co2 << '\n';
  std::cout << "life: " << oxy * co2 << '\n';
  return 0;
}