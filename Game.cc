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
  std::vector<glm::vec3> vertices = {glm::vec3(-1,-1,0), glm::vec3(0,1,0), glm::vec3(1,-1,0), 
    glm::vec3(1, 1, 0), glm::vec3(-1, 1, 0)};
  std::vector<int> triangleIndices = {0,1,2};
  // std::vector<int> squareIndices = {0, 4, 1, 0, 1, 2, 2, 1, 3};
  testMesh->addVertices(vertices, triangleIndices);

  testShader = new Shader("basicShader");
  testShader->addUniform("transform");
  // glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(1,0,0));
}


void Game::update() {
  sf::Time elapsedTime = gameClock.getElapsedTime();
  // transform = glm::translate(glm::mat4(1.0f), glm::vec3(glm::sin(elapsedTime.asSeconds()),0,0));
  auto elapsedSin = glm::sin(elapsedTime.asSeconds());
  transform = glm::rotate(glm::mat4(1.0f), elapsedSin, glm::vec3(1,0,0));
}

void Game::render() {
  testShader->bind();
  testShader->setUniform("transform", transform);
  testMesh->draw();
}
