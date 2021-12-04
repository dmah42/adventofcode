#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream inf("2021/2/input.txt");

  int aim = 0;
  int pos = 0;
  int depth = 0;

  std::string dir;
  int amount;
  while (inf >> dir >> amount) {
    if (dir == "forward") {
      pos += amount;
      depth += aim * amount;
    } else if (dir == "down") {
      aim += amount;
    } else if (dir == "up") {
      aim -= amount;
    } else {
      std::cerr << "unknown direction '" << dir << "'\n";
      return 1;
    }
  }
  std::cout << "pos: " << pos << '\n';
  std::cout << "depth: " << depth << '\n';

  return 0;
}
