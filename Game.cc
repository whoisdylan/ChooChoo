#include "Game.hh"
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <vector>

Game::Game() :
  material(Material({0,1,1})) {
}
void Game::init() {
  testMesh = new Mesh;
  testMesh->loadFile("cube.obj");

  // std::vector<glm::vec3> vertices = {{-1,-1,0}, {0,1,0}, {1,-1,0}, {0,-1,1}};
  // std::vector<int> pyramidIndices = {0,1,3, 3,1,2, 2,1,0, 0,3,2};
  // testMesh->addVertices(vertices, pyramidIndices);

  testShader = new Shader("basicShader");
  transform = new Transform();
  transform->setProjection(70.0f, 1680, 1050, 0.1, 1000);
  camera = new Camera();
  transform->camera = camera;
}


void Game::update() {
  sf::Time elapsedTime = gameClock.getElapsedTime();
  auto elapsedSin = glm::sin(elapsedTime.asSeconds());

  glm::vec3 translate = {0,0,5};
  transform->translate(translate);
  
  glm::vec3 rotate = {1,1,0};
  float rotateAngle = 50*elapsedTime.asSeconds();
  transform->rotate(rotateAngle, rotate);

  glm::vec3 scale = {elapsedSin,elapsedSin,elapsedSin};
  // transform->scale(scale);
  // transform->setTransform(translate, rotate, rotateAngle, scale);
}

void Game::input() {
  camera->input();
}

void Game::render() {
  testShader->bind();
  testShader->updateUniforms(transform->getTransform(), transform->getProjectedTransform(), material);
  testMesh->draw();
}
