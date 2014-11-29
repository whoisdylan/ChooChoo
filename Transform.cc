#include "Transform.hh"

Transform::Transform() {
}

glm::mat4 Transform::getTransform() {
  // transform = translateTransform*rotateTransform*scaleTransform;
  return translateTransform*rotateTransform*scaleTransform;
}

void Transform::setTransform(const glm::vec3 &translate, const glm::vec3 &rotate, const float angle, const glm::vec3 &scale) {
  Transform::translate(translate);
  Transform::rotate(rotate, angle);
  Transform::scale(scale);
  // transform = glm::scale(
  //     glm::rotate(
  //     glm::translate(glm::mat4(1.0f), translate),
  //     angle, rotate),
  //     scale);
}

void Transform::translate(const glm::vec3 &translate) {
  translateTransform = glm::translate(glm::mat4(1.0f), translate);
}

void Transform::rotate(const glm::vec3 &rotate, const float rotateAngle) {
  rotateTransform = glm::rotate(glm::mat4(1.0f), rotateAngle, rotate);
}

void Transform::scale(const glm::vec3 &scale) {
  scaleTransform = glm::scale(glm::mat4(1.0f), scale);
}

void Transform::scale(const float scale) {
  scaleTransform = glm::scale(glm::mat4(1.0f), {scale,scale,scale});
}
