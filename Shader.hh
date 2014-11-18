#ifndef SHADER_HH
#define SHADER_HH

#include <SFML/OpenGL.hpp>
#include <string>

class Shader {
public:
  Shader(const std::string&);
  void addVertexShader(const std::string&);
  // void addGeometryShader(const std::string&);
  void addFragmentShader(const std::string&);
  void bind();
private:
  int program;
  void addProgram(const std::string&, int);
  void compileShader();
  static std::string loadShader(const std::string&);
  static void checkShaderError(int, int, bool, const std::string&);
};

#endif
