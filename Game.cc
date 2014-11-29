#include "Game.hh"
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <vector>

Game::Game() {
}
void Game::init() {
  testMesh = new Mesh;
  std::vector<glm::vec3> vertices = {{-1,-1,0}, {0,1,0}, {1,-1,0}, {0,-1,1}};
  std::vector<int> pyramidIndices = {0,1,3, 3,1,2, 2,1,0, 0,3,2};
  testMesh->addVertices(vertices, pyramidIndices);

  testShader = new Shader("basicShader");
  testShader->addUniform("transform");
  transform = new Transform();
  transform->setProjection(70.0f, 1680, 1050, 0.1, 1000);
}


void Game::update() {
  sf::Time elapsedTime = gameClock.getElapsedTime();
  auto elapsedSin = glm::sin(elapsedTime.asSeconds());

  glm::vec3 translate = {0,0,-3};
  transform->translate(translate);
  
  glm::vec3 rotate = {1,0,0};
  float rotateAngle = 100*elapsedTime.asSeconds();
  transform->rotate(rotateAngle, rotate);

  glm::vec3 scale = {elapsedSin,elapsedSin,elapsedSin};
  transform->scale(scale);
  // transform->setTransform(translate, rotate, rotateAngle, scale);
}

void Game::render() {
  testShader->bind();
  glm::mat4 fullTransform = transform->getProjectedTransform();
  testShader->setUniform("transform", fullTransform);
  testMesh->draw();
}
