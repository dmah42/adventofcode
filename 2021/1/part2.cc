#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream inf("2021/1/input.txt");

  std::vector<int> depths;

  int depth;
  while (inf >> depth) {
    depths.push_back(depth);
  }

  int count = 0;
  int lastsum = 0;
  bool first = true;
  for (int i = 0; i < depths.size() - 2; ++i) {
    int sum = depths[i] + depths[i+1] + depths[i+2];
    if (!first && sum > lastsum) {
      ++count;
    }
    lastsum = sum;
    first = false;
  }
     
  std::cout << count << '\n';

  return 0;
}
