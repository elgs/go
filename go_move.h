#pragma once

#include <iostream>
#include <sstream>

#include "shared.h"

using namespace std;

struct Move {
  int index;
  int side = 0;
  int x = -1;
  int y = -1;

  Move() {}

  Move(int index, int x, int y, int side) {
    this->index = index;
    this->x = x;
    this->y = y;
    this->side = side;
  }

  friend ostream& operator<<(ostream& os, const Move& game);
};

ostream& operator<<(ostream& os, const Move& move) {
  if (move.index > 0) {
    os << "move: " << move.index << ", x: " << static_cast<char>(move.x + 97)
       << "(" << move.x << ")"
       << ", y: " << move.y << ", side: " << (move.side == 1 ? "●" : "○")
       << endl;
  }
  return os;
}