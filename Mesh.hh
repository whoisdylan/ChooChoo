#ifndef MESH_HH
#define MESH_HH

#include <glm/vec3.hpp>
#include <vector>
#include "Renderable.hh"

class Mesh : public Renderable {
public:
  Mesh();
  void addVertices(std::vector<glm::vec3>);
  virtual void draw();
private:
  unsigned int vbo;
  int size;
  int vertexSize;
};

#endif
