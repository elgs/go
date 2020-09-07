#include "go_board.h"
#include "go_game.h"
#include "go_move.h"
#include "shared.h"

using namespace std;

int main() {
  auto game = new Game();

  try {
    game->move(4, 4);
    game->move(3, 3);
    game->move(3, 3);
  } catch (exception& e) {
    cout << e.what() << endl;
  }
  cout << *game;

  return 0;
}