#ifndef ENGINE_GUARD
#define ENGINE_GUARD

// #define GLEW_STATIC

#include <GL/glew.h>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Mesh.hh"
#include "Game.hh"
// #include "Input.hh"

using namespace std;

class Game;

class Engine {
friend class Input;
public:
  Engine(unsigned int windowWidth, unsigned int windowHeight, double framerate, Game *game);
  ~Engine();
  void createWindow(const string& title);
  void start();
  void stop();
  void render();
private:
  sf::Window gameWindow;
  void run();
  bool isRunning;
  unsigned int windowWidth;
  unsigned int windowHeight;
  sf::Time frameTime;
  Game *game;
};

#endif
