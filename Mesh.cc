#include "Mesh.hh"
#include <iostream>

Mesh::Mesh() {
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ibo);
  size = 0;
}

void Mesh::addVertices(std::vector<glm::vec3> &vertices, std::vector<int> &indices) {
  // std::cout << vertices[0].x << " " << vertices[0].y << " " << vertices[0].z << std::endl;
  // std::cout << glGetString(GL_VERSION) << std::endl;
  size = indices.size();
  vertexSize = sizeof(vertices[0]);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(int), &indices[0], GL_STATIC_DRAW);

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
}

void Mesh::draw() {
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
}
