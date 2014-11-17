#include "Input.hh"

void Input::update(Engine *engine) {
  sf::Event event;
  while (engine->gameWindow.pollEvent(event)) {
    switch (event.type) {
      case (sf::Event::Closed):
        engine->stop();
        break;
      case (sf::Event::KeyPressed):
        if (event.key.code == sf::Keyboard::Escape) {
          engine->stop();
        }
        break;
      default:
        break;
    }
  }
}
