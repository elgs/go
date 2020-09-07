#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "go_move.h"
#include "shared.h"

using namespace std;

struct Board {
  int state[BOARD_LINES * BOARD_LINES]{};
  int side = 1;
  Move move;

  Board() {}
  Board(Move move) { this->move = move; }
  ~Board() {}

  int getAt(int x, int y) const { return state[x * BOARD_LINES + y]; }
  void setAt(int v, int x, int y) { state[x * BOARD_LINES + y] = v; }

  friend ostream& operator<<(ostream& os, const Board& board);
};

ostream& operator<<(ostream& os, const Board& board) {
  os << board.move << endl;
  for (int i = 0; i < BOARD_LINES; ++i) {
    for (int j = 0; j < BOARD_LINES; ++j) {
      int v = board.getAt(i, j);
      if (v == 0) {
        os << "+";
      } else if (v == 1) {
        os << "●";
      } else if (v == 2) {
        os << "○";
      }
      os << " ";
    }
    os << endl;
  }
  return os;
}