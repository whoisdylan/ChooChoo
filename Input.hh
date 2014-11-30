#ifndef INPUT__GUARD
#define INPUT__GUARD

#include "Engine.hh"
#include <SFML/Window.hpp>
#include <queue>

class Input {
public:
  static void update(Engine *);
  static queue<sf::Keyboard::Key> pressedKeys;
  static bool downKeys[sf::Keyboard::KeyCount];
  // static bool keyHit[sf::Keyboard::KeyCount];
  // static bool isKeyHit(sf::Keyboard::Key);
};

#endif
