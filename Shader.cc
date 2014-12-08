#include "Shader.hh"
#include <fstream>
#include <iostream>
#include <cassert>

Shader::Shader(const std::string& filename) {
  program = glCreateProgram();
  if (program == 0) {
    std::cerr << "Error creating shader program" << std::endl;
    exit(1);
  }

  std::string vertexShader = loadShader(filename + ".vs");
  std::string fragmentShader = loadShader(filename + ".fs");

  addVertexShader(vertexShader);
  addFragmentShader(fragmentShader);

  compileShader();

  addUniform("transform");
  addUniform("color");
}

void Shader::bind() {
  glUseProgram(program);
}

void Shader::updateUniforms(glm::mat4 worldMatrix, glm::mat4 projectedMatrix, Material &material) {
  setUniform("transform", projectedMatrix);
  setUniform("color", material.color);
}

void Shader::addUniform(const std::string &name) {
  int location = glGetUniformLocation(program, name.c_str());
  assert(location != -1);
  uniformMap.insert(std::pair<std::string, unsigned int>(name, location));
}

void Shader::setUniform(const std::string &name, int value) {
  glUniform1i(uniformMap[name], value);
}

void Shader::setUniform(const std::string &name, float value) {
  glUniform1f(uniformMap[name], value);
}

void Shader::setUniform(const std::string &name, glm::vec3 &value) {
  glUniform3f(uniformMap[name], value.x, value.y, value.z);
}

void Shader::setUniform(const std::string &name, glm::mat4 &value) {
  glUniformMatrix4fv(uniformMap[name], 1, GL_FALSE, &(value[0][0]));
}

void Shader::addVertexShader(const std::string& text) {
  addProgram(text, GL_VERTEX_SHADER);
}

// void Shader::addGeometryShader(const std::string& text) {
//   addProgram(text, GL_GEOMETRY_SHADER);
// }

void Shader::addFragmentShader(const std::string& text) {
  addProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::compileShader() {
  glLinkProgram(program);
  checkShaderError(program, GL_LINK_STATUS, true, "Error linking shader program");

  glValidateProgram(program);
  checkShaderError(program, GL_VALIDATE_STATUS, true, "Invalid shader program");
}

void Shader::checkShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage) {
  GLint success = 0;
  GLchar error[1024] = { 0 };

  if (isProgram) {
    glGetProgramiv(shader, flag, &success);
  } else {
    glGetShaderiv(shader, flag, &success);
  }

  if (!success) {
    if (isProgram) {
      glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    } else {
      glGetShaderInfoLog(shader, sizeof(error), NULL, error);
    }
    fprintf(stderr, "%s: '%s'\n", errorMessage.c_str(), error);
  }
}

void Shader::addProgram(const std::string& text, int shaderType) {
  int shader = glCreateShader(shaderType);
  if (shader == 0) {
    std::cerr << "Error creating shader of type " << shaderType << std::endl;
    exit(1);
  }

  const GLchar* p[1];
  p[0] = text.c_str();
  GLint lengths[1];
  lengths[0] = text.length();

  glShaderSource(shader, 1, p, lengths);
  glCompileShader(shader);

  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLchar InfoLog[1024];

    glGetShaderInfoLog(shader, 1024, NULL, InfoLog);
    fprintf(stderr, "Error compiling shader type %d: '%s'\n", shader, InfoLog);

    exit(1);
  } 
  
  glAttachShader(program, shader);
}

std::string Shader::loadShader(const std::string& fileName) {
  std::ifstream file;
  file.open((fileName).c_str());

  std::string output;
  std::string line;

  if (file.is_open()) {
    while (file.good()) {
      getline(file, line);

      if (line.find("#include") == std::string::npos) {
        output.append(line + "\n");
      } else {
        int breakPoint = line.find(" ");
        std::string includeFileName = line.substr(breakPoint, line.length()-breakPoint);
        includeFileName = includeFileName.substr(1,includeFileName.length() - 2);

        std::string toAppend = loadShader(includeFileName);
        output.append(toAppend + "\n");
      }
    }
  } else {
    std::cerr << "Unable to load shader: " << fileName << std::endl;
  }

  return output;
}
