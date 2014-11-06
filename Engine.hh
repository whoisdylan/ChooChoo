#ifndef ENGINE_GUARD
#define ENGINE_GUARD

#include <string>
#include <SFML/Window.hpp>

using namespace std;

class Game;

<<<<<<< HEAD
namespace ChooChoo {
=======
>>>>>>> 76fec15b001f7ddbef7e5730f0403f364f387221
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
<<<<<<< HEAD
}
=======
>>>>>>> 76fec15b001f7ddbef7e5730f0403f364f387221

#endif
