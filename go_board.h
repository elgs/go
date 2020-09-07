#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "shared.h"


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
