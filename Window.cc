#include "Window.hh"

// RenderWindow window{{windowWidth, windowHeight}, "Baller"};
void baller::Window::drawCourse(Vector2<int> teeOffLocation, Vector2<int> holeLocation) {
  RectangleShape teeOffBox(Vector2f(100,40));
  teeOffBox.setPosition(100*teeOffLocation.x, 100*teeOffLocation.y);
  teeOffBox.setOrigin(teeOffBox.getSize()/2.f);
  // teeOffBox.setPosition(0,0);
  teeOffBox.setFillColor(Color::Green);
  CircleShape hole(10);
  hole.setPosition(100*holeLocation.x, 100*holeLocation.y);
  hole.setOrigin(hole.getRadius(),hole.getRadius());
  hole.setFillColor(Color::Red);
  this->window.draw(teeOffBox);
  this->window.draw(hole);
}
