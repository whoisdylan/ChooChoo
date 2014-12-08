#ifndef MATERIAL_GUARD
#define MATERIAL_GUARD

#include <glm/vec3.hpp>

class Material {
public:
  Material(glm::vec3);
  glm::vec3 color;
private:
};

#endif
