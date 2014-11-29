#include "Camera.hh"
#include "Input.hh"
#include <glm/geometric.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <iostream>

Camera::Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up):
  position(position),
  forward(glm::normalize(forward)),
  up(glm::normalize(up)) {}

void Camera::move(glm::vec3 direction, float distance) {
  position = position + (direction*distance);
  std::cout << "posX = " << position.x << " posY = " << position.y << " posZ = " << position.z << std::endl;
}

void Camera::rotateX(float angle) {
  glm::vec3 horizontalAxis = glm::normalize(glm::cross(absoluteUp, forward));

  forward = glm::normalize(glm::rotate(forward, angle, horizontalAxis));

  up = glm::normalize(glm::cross(forward, horizontalAxis));
}

void Camera::rotateY(float angle) {
  glm::vec3 horizontalAxis = glm::normalize(glm::cross(absoluteUp, forward));

  forward = glm::normalize(glm::rotate(forward, angle, absoluteUp));

  up = glm::normalize(glm::cross(forward, horizontalAxis));
}

glm::vec3 Camera::left() {
  return glm::normalize(glm::cross(forward, up));
}

glm::vec3 Camera::right() {
  return glm::normalize(glm::cross(up, forward));
}

void Camera::input() {
  const float moveAmount = .01;
  const float rotateAmount = 1;

  if (Input::isKeyHit(sf::Keyboard::Up)) {
    move(forward, moveAmount);
  }
  if (Input::isKeyHit(sf::Keyboard::Down)) {
    move(forward, -moveAmount);
  }
  if (Input::isKeyHit(sf::Keyboard::Left)) {
    move(left(), -moveAmount);
  }
  if (Input::isKeyHit(sf::Keyboard::Right)) {
    move(right(), -moveAmount);
  }

  // if (Input::isKeyHit(sf::Keyboard::Up)) {
  //   rotateX(-rotateAmount);
  // }
  // if (Input::isKeyHit(sf::Keyboard::Down)) {
  //   rotateX(rotateAmount);
  // }
  // if (Input::isKeyHit(sf::Keyboard::Left)) {
  //   rotateY(-rotateAmount);
  // }
  // if (Input::isKeyHit(sf::Keyboard::Right)) {
  //   rotateY(rotateAmount);
  // }
}
