#include "go.hpp"

int main() {
  auto game = new Game();

  try {
    game->move(4, 4);
    game->move(3, 3);
    game->move(3, 3);
  } catch (exception& e) {
    cout << e.what();
  }
  game->print();

  return 0;
}