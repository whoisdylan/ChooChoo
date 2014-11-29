#ifndef TRANSFORM_GUARD
#define TRANSFORM_GUARD

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

class Transform {
public:
  Transform();
  glm::mat4 getTransform();
  glm::mat4 getProjectedTransform();
  void setProjection(const float, const float, const float, const float, const float);
  void setTransform(const glm::vec3 &, const glm::vec3 &, const float, const glm::vec3 &);
  void translate(const glm::vec3 &);
  void rotate(const float, const glm::vec3 &);
  void scale(const glm::vec3 &);
  void scale(const float);
  // glm::mat4 transform;
private:
  glm::mat4 rotateTransform;
  glm::mat4 translateTransform;
  glm::mat4 scaleTransform;

  float fov;
  float zNear;
  float zFar;
  float width;
  float height;
};

#endif
