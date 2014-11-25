#ifndef SHADER_HH
#define SHADER_HH

#include <SFML/OpenGL.hpp>
#include <string>
#include <map>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>

class Shader {
public:
  Shader(const std::string&);
  void addVertexShader(const std::string&);
  // void addGeometryShader(const std::string&);
  void addFragmentShader(const std::string&);
  void bind();

  void addUniform(const std::string&);
  void setUniform(const std::string &, int);
  void setUniform(const std::string &, float);
  void setUniform(const std::string &, glm::vec3 &);
  void setUniform(const std::string &, glm::mat4 &);
private:
  std::map<std::string, int> uniformMap;
  int program;
  void addProgram(const std::string&, int);
  void compileShader();
  static std::string loadShader(const std::string&);
  static void checkShaderError(int, int, bool, const std::string&);
};

#endif
