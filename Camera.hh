#ifndef CAMERA_GUARD
#define CAMERA_GUARD

#include <glm/vec3.hpp>

class Camera {
public:
  Camera(glm::vec3={0,0,0}, glm::vec3={0,0,1}, glm::vec3={0,1,0});

  void move(glm::vec3, float);
  void rotateX(float);
  void rotateY(float);

  glm::vec3 position;
  glm::vec3 forward;
  glm::vec3 up;
  const glm::vec3 absoluteUp = {0,1,0};

  glm::vec3 left();
  glm::vec3 right();

  void input();

private:
};

#endif
