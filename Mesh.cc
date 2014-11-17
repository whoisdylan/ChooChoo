#include "Mesh.hh"
#include <SFML/OpenGL.hpp>
#include <iostream>

Mesh::Mesh() {
  glGenBuffers(1, &vbo);
  size = 0;
}

void Mesh::addVertices(std::vector<glm::vec3> vertices) {
  // std::cout << vertices[0].x << " " << vertices[0].y << " " << vertices[0].z << std::endl;
  std::cout << glGetString(GL_VERSION) << std::endl;
  size = vertices.size();
  vertexSize = sizeof(vertices[0]);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
}

void Mesh::draw() {
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, 0);
  glDrawArrays(GL_TRIANGLES, 0, size);

  glDisableVertexAttribArray(0);
}
