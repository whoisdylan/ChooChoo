#include "Input.hh"
#include <iostream>

queue<sf::Keyboard::Key> Input::pressedKeys;
bool Input::downKeys[sf::Keyboard::KeyCount];
// bool Input::keyHit[sf::Keyboard::KeyCount];

void Input::update(Engine *engine) {
  sf::Event event;
  while (engine->gameWindow.pollEvent(event)) {
    // while (!pressedKeys.empty()) {
    //   keyHit[pressedKeys.front()] = false;
    //   pressedKeys.pop();
    // }
    switch (event.type) {
      case (sf::Event::Closed):
        engine->stop();
        break;
      case (sf::Event::KeyPressed):
        // std::cout << event.key.code << " is hit" << std::endl;
        if (event.key.code == sf::Keyboard::Escape) {
          engine->stop();
        } else {
          downKeys[event.key.code] = true;
          // keyHit[event.key.code] = true;
          // pressedKeys.push(event.key.code);
        }
        break;
      case (sf::Event::KeyReleased):
        // std::cout << event.key.code << " is released" << std::endl;
        downKeys[event.key.code] = false;
        break;
      default:
        break;
    }
  }
}

// bool Input::isKeyHit(sf::Keyboard::Key key) {
//   return keyHit[key];
// }
