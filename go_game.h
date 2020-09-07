#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "go_board.h"

#define BOARD_LINES 19

using namespace std;

struct Game {
  vector<Board>* boards;
  Game() {
    boards = new vector<Board>();
    boards->push_back(Board{});
  }
  ~Game() { delete boards; }

  void move(int x, int y) {
    auto board = boards->back();
    if (board.getAt(x, y) != 0) {
      stringstream s;
      s << "Invalid move at: " << x << y;
      throw runtime_error(s.str());
    }
    ++board.move;
    board.side = board.side == 1 ? 2 : 1;
    board.setAt(board.side, x, y);
    boards->push_back(board);
  }

  void print() {
    for (auto& board : *boards) {
      board.print();
    }
  }
};
