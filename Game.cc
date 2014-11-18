#include "Game.hh"
#include <glm/vec3.hpp>
#include <vector>

Game::Game() {
}
void Game::init() {
  testMesh = new Mesh;
  std::vector<glm::vec3> triangle = {glm::vec3(-1,-1,0), glm::vec3(0,1,0), glm::vec3(1,-1,0)};
  testMesh->addVertices(triangle);

  testShader = new Shader("basicShader");
}

void Game::render() {
  testShader->bind();
  testMesh->draw();
}
