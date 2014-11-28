#include "Game.hh"
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <vector>
#include <iostream>

Game::Game() {
}
void Game::init() {
  testMesh = new Mesh;
  std::vector<glm::vec3> vertices = {glm::vec3(-1,-1,0), glm::vec3(0,1,0), glm::vec3(1,-1,0), 
    glm::vec3(1, 1, 0), glm::vec3(-1, 1, 0)};
  std::vector<int> triangleIndices = {0,1,2};
  // std::vector<int> squareIndices = {0, 4, 1, 0, 1, 2, 2, 1, 3};
  testMesh->addVertices(vertices, triangleIndices);

  testShader = new Shader("basicShader");
  testShader->addUniform("transform");
  glm::vec3 translate = {0,0,0};
  glm::vec3 rotate = {0,0,0};
  float rotateAngle = 0;
  glm::vec3 scale = {1,1,1};
  transform = new Transform(translate, rotate, rotateAngle, scale);
}


void Game::update() {
  sf::Time elapsedTime = gameClock.getElapsedTime();
  auto elapsedSin = glm::sin(elapsedTime.asSeconds());
  glm::vec3 translate = {0,0,0};
  glm::vec3 rotate = {1,0,0};
  // float rotateAngle = 100*elapsedTime.asSeconds();
  float rotateAngle = 0;
  glm::vec3 scale = {elapsedSin,elapsedSin,elapsedSin};
  // glm::vec3 scale = {1,1,1};
  transform->setTransform(translate, rotate, rotateAngle, scale);
}

void Game::render() {
  testShader->bind();
  testShader->setUniform("transform", transform->transform);
  testMesh->draw();
}
