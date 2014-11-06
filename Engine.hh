#ifndef ENGINE_GUARD
#define ENGINE_GUARD

#include <string>
#include <SFML/Window.hpp>

using namespace std;

class Game;

namespace ChooChoo {
class Engine {
public:
  Engine(int windowWidth, int windowHeight, double framerate, Game *game);
  ~Engine();
  void createWindow(const string& title);
  void start();
  void stop();
private:
  void run();
  bool isRunning;
  int windowWidth;
  int windowHeight;
  sf::Time frameTime;
  Game *game;
};
}

#endif
