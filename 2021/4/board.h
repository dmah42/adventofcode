#include <array>
#include <utility>

class Board {
 public:
  Board Transpose() const;

  int Get(int row, int col) const { return _board[row][col].first; }
  void Set(int row, int col, int value) { _board[row][col].first = value; }
  bool Mark(int value);

  bool Winner() const;
  int Score(int called) const;

  std::string ToString() const;

 private:
  std::array<std::array<std::pair<int, bool>, 5>, 5> _board;
};