#include <fstream>
#include <iostream>

int main() {
  std::ifstream inf("input.txt");

  bool isfirst = true;
  int count = 0;
  int lastd = 0;
  int depth;
  while (inf >> depth) {
    if (!isfirst && depth > lastd) {
      ++count;
    }
    lastd = depth;

    isfirst = false;
  }
     
  std::cout << count << '\n';

  return 0;
}
