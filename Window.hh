#ifndef WINDOW_GUARD
#define WINDOW_GUARD

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
// using namespace sf;

constexpr int windowWidth{1680}, windowHeight{1050};

<<<<<<< HEAD
namespace ChooChoo {
=======
>>>>>>> 76fec15b001f7ddbef7e5730f0403f364f387221
class Window {
  public:
    sf::RenderWindow window{{windowWidth, windowHeight}, "Baller"};
    void drawCourse(sf::Vector2i, sf::Vector2i);
    void dispose();
};
<<<<<<< HEAD
}
=======
>>>>>>> 76fec15b001f7ddbef7e5730f0403f364f387221

#endif
