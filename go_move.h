#pragma once

#include <iostream>
#include <sstream>

#include "shared.h"

using namespace std;

struct Move {
  int index;
  int x = -1;
  int y = -1;

  Move() {}

  Move(int index, int x, int y) {
    this->index = index;
    this->x = x;
    this->y = y;
  }

  friend ostream& operator<<(ostream& os, const Move& game);
};

ostream& operator<<(ostream& os, const Move& move) {
  os << "Index: " << move.index << ", x: " << move.x << ", y: " << move.y;
  return os;
}