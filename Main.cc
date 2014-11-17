#include "Engine.hh"
#include "Mesh.hh"
#include <iostream>

  // Engine(unsigned int windowWidth, unsigned int windowHeight, double framerate, Game *game);
int main() {
  Engine *choochoo = new Engine(1680, 1050, 200.0,(Game *) NULL);
  choochoo->createWindow("Game: The Game");
  choochoo->start();
  return 0;
}


