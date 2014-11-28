#ifndef TRANSFORM_GUARD
#define TRANSFORM_GUARD

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

class Transform {
public:
  Transform(const glm::vec3 &, const glm::vec3 &, const float, const glm::vec3 &);
  void setTransform(const glm::vec3 &, const glm::vec3 &, const float, const glm::vec3 &);
  glm::mat4 transform;
private:
  // glm::mat4 rotateTransform;
  // glm::mat4 translateTransform;
  // glm::mat4 scaleTransform;
};

#endif
