#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

constexpr int windowWidth{1680}, windowHeight{1050};

namespace baller {
  class Window {
  public:
    RenderWindow window{{windowWidth, windowHeight}, "Baller"};
    void drawCourse(Vector2<int>, Vector2<int>);
  };
}
