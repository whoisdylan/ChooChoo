#ifndef WINDOW_GUARD
#define WINDOW_GUARD

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
// using namespace sf;

// constexpr int windowWidth{1680}, windowHeight{1050};

namespace ChooChoo {
class Window {
  public:
    
    sf::RenderWindow window{{windowWidth, windowHeight}, "Baller"};
    void drawCourse(sf::Vector2i, sf::Vector2i);
    void dispose();
};
}

#endif
