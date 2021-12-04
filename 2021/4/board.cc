#include "board.h"

#include <string>

#include "absl/strings/str_cat.h"

bool Board::Mark(int value) {
  bool marked = false;
  for (auto& row : _board) {
    for (auto& cell : row) {
      if (cell.first == value) {
        marked = true;
        cell.second = true;
      }
    }
  }
  return marked;
}

bool Board::Winner() const {
  for (const auto& row : _board) {
    bool allMarked = row[0].second;
    for (const auto& cell : row) {
      allMarked = allMarked && cell.second;
    }
    if (allMarked) return true;
  }

  Board t = Transpose();
  for (const auto& row : t._board) {
    bool allMarked = row[0].second;
    for (const auto& cell : row) {
      allMarked = allMarked && cell.second;
    }
    if (allMarked) return true;
  }

  return false;
}

int Board::Score(int called) const {
  int sum = 0;
  for (const auto& row : _board) {
    for (const auto& cell : row) {
      if (!cell.second) sum += cell.first;
    }
  }

  return sum * called;
}

Board Board::Transpose() const {
  Board b;
  for (int r = 0; r < _board.size(); ++r) {
    for (int c = 0; c < _board[r].size(); ++c) {
      b.Set(c, r, _board[r][c].first);
      if (_board[r][c].second) b.Mark(_board[r][c].first);
    }
  }
  return b;
}

std::string Board::ToString() const {
  std::string s;
  for (const auto& row : _board) {
    for (const auto& cell : row) {
      s += absl::StrCat(cell.first);
      if (cell.second)
        s += "* ";
      else
        s += "  ";
    }
    s += '\n';
  }
  return s;
}