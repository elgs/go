#include "go_board.h"
#include "go_game.h"
#include "go_move.h"
#include "shared.h"

using namespace std;

int main() {
  auto game = new Game();

  game->move(4, 4);
  game->move(3, 3);
  game->move(5, 3);
  game->move(5, 6);
  cout << *game;

  delete game;

  return 0;
}