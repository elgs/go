#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "go_board.h"
#include "shared.h"

using namespace std;

struct Game {
  vector<Board> boards{};
  Game() { boards.push_back(Board{}); }
  ~Game() {}

  void move(int x, int y);

  friend ostream& operator<<(ostream& os, const Game& game);
};

ostream& operator<<(ostream& os, const Game& game) {
  for (auto& board : game.boards) {
    os << board;
  }
  return os;
}

void Game::move(int x, int y) {
  auto board = boards.back();
  if (board.getAt(x, y) != 0) {
    stringstream s;
    s << "Invalid move at: " << x << y;
    throw runtime_error(s.str());
  }
  ++board.move.index;
  board.move.x = x;
  board.move.y = y;
  board.side = board.side == 1 ? 2 : 1;
  board.setAt(board.side, x, y);
  boards.push_back(board);
};
