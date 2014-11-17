#ifndef ENGINE_GUARD
#define ENGINE_GUARD

#include <string>
#include <SFML/Window.hpp>
#include "Mesh.hh"
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
  Mesh *testMesh;
};

#endif
