#ifndef GAME_HH
#define GAME_HH

#include "Mesh.hh"
#include "Shader.hh"
#include "Transform.hh"
#include "Camera.hh"
#include <SFML/Window.hpp>
#include <glm/matrix.hpp>

class Game {
public:
  Game();
  void init();
  Shader *testShader;
  Mesh *testMesh;
  void update();
  void input();
  void render();
  Camera *camera;
private:
  sf::Clock gameClock;
  Transform *transform;
};

#endif
