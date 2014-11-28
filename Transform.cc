#include "Transform.hh"

Transform::Transform(const glm::vec3 &translate, const glm::vec3 &rotate, const float angle, const glm::vec3 &scale) {
  // transform = glm::translate(glm::mat4(1.0f), glm::vec3(glm::sin(elapsedTime.asSeconds()),0,0));
  transform = glm::scale(
      glm::rotate(
      glm::translate(glm::mat4(1.0f), translate),
      angle, rotate),
      scale);
}

void Transform::setTransform(const glm::vec3 &translate, const glm::vec3 &rotate, const float angle, const glm::vec3 &scale) {
  transform = glm::scale(
      glm::rotate(
      glm::translate(glm::mat4(1.0f), translate),
      angle, rotate),
      scale);
}
