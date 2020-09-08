#include "go_board.h"
#include "go_game.h"
#include "go_move.h"
#include "shared.h"

using namespace std;

int main() {
  auto game = new Game();

  int x, y;
  while (true) {
    auto latestBoard = game->boards.back();
    cout << latestBoard;
    cout << (latestBoard.move.side == 1 ? "● " : "○ ");
    cin >> x >> y;
    game->move(x, y);
  };

  delete game;

  return 0;
}