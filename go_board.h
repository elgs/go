#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "go_move.h"
#include "shared.h"

using namespace std;

struct GroupStats {
  int id = 0;
  int side = -1;
  vector<Move> stones{};
  vector<Move> liberties{};
};

struct Board {
  int state[LINES * LINES]{};
  Move move{};
  vector<GroupStats> groups{};

  int getAt(int x, int y) const { return state[x * LINES + y]; }
  void setAt(int v, int x, int y) { state[x * LINES + y] = v; }

  void stats();
  void walk(bool* visits, int x, int y);

  friend ostream& operator<<(ostream& os, const Board& board);
};

void Board::stats() {
  bool visits[LINES * LINES]{};
  for (auto i = 0; i < LINES; ++i) {
    for (auto j = 0; j < LINES; ++j) {
      if (this->state[i * LINES + j] == 0 || visits[i * LINES + j]) {
        continue;
      }
      this->walk(visits, i, j);
    }
  }
};

void Board::walk(bool* visits, int x, int y) { visits[x * LINES + y] = true; };

ostream& operator<<(ostream& os, const Board& board) {
  os << board.move << endl;
  os << "   ";
  for (auto i = 0; i < LINES; ++i) {
    os << i % 10 << " ";
  }
  os << endl;
  os << "   ";
  for (auto i = 0; i < LINES; ++i) {
    os << static_cast<char>(i + 97) << " ";
  }
  os << endl;
  for (auto i = 0; i < LINES; ++i) {
    os << setw(2) << i << " ";
    for (auto j = 0; j < LINES; ++j) {
      auto v = board.getAt(i, j);
      if (v == 0) {
        auto a = false;
        auto b = false;
        if (LINES == 13 || LINES == 19) {
          a = a || i == 3 || i == (LINES - 1) / 2 || i == LINES - 4;
          b = b || j == 3 || j == (LINES - 1) / 2 || j == LINES - 4;
        } else if (LINES == 9) {
          a = a || i == 2 || i == (LINES - 1) / 2 || i == LINES - 3;
          b = b || j == 2 || j == (LINES - 1) / 2 || j == LINES - 3;
        }
        auto isStar = a && b;
        os << (isStar ? "\033[1;33m*\033[0m" : "+");
      } else if (v == 1) {
        os << "○";
      } else if (v == 2) {
        os << "●";
      }
      os << " ";
    }
    os << i << endl;
  }
  os << "   ";
  for (auto i = 0; i < LINES; ++i) {
    os << static_cast<char>(i + 97) << " ";
  }
  os << endl;
  os << "   ";
  for (auto i = 0; i < LINES; ++i) {
    os << i % 10 << " ";
  }
  os << endl << endl;
  return os;
}