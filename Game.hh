#ifndef GAME_HH
#define GAME_HH

#include "Mesh.hh"
#include "Shader.hh"

class Game {
public:
  Game();
  void init();
  Shader *testShader;
  Mesh *testMesh;
  void render();
};

#endif
