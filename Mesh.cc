#include "Mesh.hh"
#include "Util.hh"
#include <fstream>
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

void Mesh::loadFile(const std::string &fileName) {
  std::ifstream file;
  file.open((fileName).c_str());

  std::string output;
  std::string line;

  std::vector<glm::vec3> vertices;
  std::vector<int> indices;

  if (file.is_open()) {
    while (file.good()) {
      getline(file, line);
      if (line[0] == '#') {
        continue;
      }
      std::vector<std::string> tokens = Util::split(line, " ");
      if (tokens[0] == "v") {
        vertices.push_back({std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3])});
      } else if (tokens[0] == "f") {
        for (auto iter = tokens.begin()+1; iter != tokens.end(); iter++) {
          indices.push_back(std::stoi(*iter)-1);
        }
      }
    }
    addVertices(vertices, indices);
  } else {
    std::cerr << "Unable to load mesh: " << fileName << std::endl;
  }
}
