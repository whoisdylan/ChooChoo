#include "Transform.hh"

Transform::Transform() {
  translate({0.0,0.0,0.0});
  rotate(0.0, {1.0,0.0,0.0});
  scale(1.0);
}

glm::mat4 Transform::getTransform() {
  // transform = translateTransform*rotateTransform*scaleTransform;
  
  glm::mat4 cameraMatrix = glm::lookAt(camera->position, camera->forward, camera->up);
  return translateTransform*rotateTransform*scaleTransform*cameraMatrix;
}

glm::mat4 Transform::getProjectedTransform() {
  return glm::perspectiveFov(fov, width, height, zNear, zFar)*getTransform();
}

void Transform::setProjection(const float fov, const float width, const float height, const float zNear, const float zFar) {
  this->fov = fov;
  this->width = width;
  this->height = height;
  this->zNear = zNear;
  this->zFar = zFar;
}

void Transform::setTransform(const glm::vec3 &translate, const glm::vec3 &rotate, const float angle, const glm::vec3 &scale) {
  Transform::translate(translate);
  Transform::rotate(angle, rotate);
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

void Transform::rotate(const float rotateAngle, const glm::vec3 &rotate) {
  rotateTransform = glm::rotate(glm::mat4(1.0f), rotateAngle, rotate);
}

void Transform::scale(const glm::vec3 &scale) {
  scaleTransform = glm::scale(glm::mat4(1.0f), scale);
}

void Transform::scale(const float scale) {
  scaleTransform = glm::scale(glm::mat4(1.0f), {scale,scale,scale});
}
