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
  std::vector<glm::vec3> triangle = {glm::vec3(-1,-1,0), glm::vec3(0,1,0), glm::vec3(1,-1,0)};
  testMesh->addVertices(triangle);

  testShader = new Shader("basicShader");
  testShader->addUniform("transform");
  // glm::mat4 translateX = glm::translate(glm::mat4(1.0f), glm::vec3(1,0,0));
}


void Game::update() {
  sf::Time elapsedTime = gameClock.getElapsedTime();
  translateX = glm::translate(glm::mat4(1.0f), glm::vec3(glm::sin(elapsedTime.asSeconds()),0,0));
}

void Game::render() {
  testShader->bind();
  testShader->setUniform("transform", translateX);
  testMesh->draw();
}
