#ifndef MESH_HH
#define MESH_HH

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include "Renderable.hh"

class Mesh : public Renderable {
public:
  Mesh();
  void addVertices(std::vector<glm::vec3> &, std::vector<int> &);
  virtual void draw();
private:
  unsigned int vao;
  unsigned int vbo;
  unsigned int ibo;
  int size;
  int vertexSize;
};

#endif
