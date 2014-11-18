#include "Game.hh"
#include <glm/vec3.hpp>
#include <vector>
#include <iostream>

Game::Game() {
}
void Game::init() {
  std::cout << "CountDebugula 6" << std::endl;
  testMesh = new Mesh;
  std::cout << "CountDebugula 7" << std::endl;
  std::vector<glm::vec3> triangle = {glm::vec3(-1,-1,0), glm::vec3(0,1,0), glm::vec3(1,-1,0)};
  std::cout << "CountDebugula 8" << std::endl;
  testMesh->addVertices(triangle);

  testShader = new Shader("basicShader");
}

void Game::render() {
  testShader->bind();
  testMesh->draw();
}
