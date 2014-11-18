#include "Engine.hh"
#include "Mesh.hh"
#include "Game.hh"
#include <iostream>

  // Engine(unsigned int windowWidth, unsigned int windowHeight, double framerate, Game *game);
int main() {
  Game *game = new Game;
  Engine *choochoo = new Engine(1680, 1050, 200.0, game);
  choochoo->createWindow("Game: The Game");
  choochoo->start();
  return 0;
}


