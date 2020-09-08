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

  void move(int x, int y);

  friend ostream& operator<<(ostream& os, const Game& game);
};

ostream& operator<<(ostream& os, const Game& game) {
  for (auto& board : game.boards) {
    os << board << endl;
  }
  return os;
}

void Game::move(int x, int y) {
  auto board = boards.back();
  board.groups.clear();
  if (board.getAt(x, y) != 0) {
    stringstream s;
    s << "invalid move at: " << x << ", " << y;
    throw runtime_error(s.str());
  }
  ++board.move.index;
  board.move.x = x;
  board.move.y = y;
  board.move.side = board.move.side == 1 ? 2 : 1;
  board.setAt(board.move.side, x, y);
  boards.push_back(board);
};
