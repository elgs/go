#ifndef GO_H
#define GO_H

#include <iostream>
#include <sstream>
#include <vector>

#define BOARD_LINES 19

using namespace std;

struct Board {
  int state[BOARD_LINES * BOARD_LINES];
  int move = 0;
  int side = 1;

  int& getAt(int x, int y) { return state[x * BOARD_LINES + y]; }

  void setAt(int v, int x, int y) { state[x * BOARD_LINES + y] = v; }

  void print() {
    cout << "Move: " << move << endl;
    for (int i = 0; i < BOARD_LINES; ++i) {
      for (int j = 0; j < BOARD_LINES; ++j) {
        int v = this->getAt(i, j);
        if (v == 0) {
          cout << "+";
        } else if (v == 1) {
          cout << "●";
        } else if (v == 2) {
          cout << "○";
        }
        cout << " ";
      }
      cout << endl;
    }
  }
};

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

#endif