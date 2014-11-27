#ifndef GAME_HH
#define GAME_HH

#include "Mesh.hh"
#include "Shader.hh"
#include <SFML/Window.hpp>
#include <glm/matrix.hpp>

class Game {
public:
  Game();
  void init();
  Shader *testShader;
  Mesh *testMesh;
  void update();
  void render();
private:
  sf::Clock gameClock;
  glm::mat4 transform;
};

#endif
