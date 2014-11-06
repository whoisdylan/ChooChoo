#include "Window.hh"

// RenderWindow window{{windowWidth, windowHeight}, "Baller"};
<<<<<<< HEAD
void ChooChoo::Window::drawCourse(sf::Vector2i teeOffLocation, sf::Vector2i holeLocation) {
=======
void Window::drawCourse(sf::Vector2i teeOffLocation, sf::Vector2i holeLocation) {
>>>>>>> 76fec15b001f7ddbef7e5730f0403f364f387221
  sf::RectangleShape teeOffBox(sf::Vector2f(100,40));
  teeOffBox.setPosition(100*teeOffLocation.x, 100*teeOffLocation.y);
  teeOffBox.setOrigin(teeOffBox.getSize()/2.f);
  // teeOffBox.setPosition(0,0);
  teeOffBox.setFillColor(sf::Color::Green);
  sf::CircleShape hole(10);
  hole.setPosition(100*holeLocation.x, 100*holeLocation.y);
  hole.setOrigin(hole.getRadius(),hole.getRadius());
  hole.setFillColor(sf::Color::Red);
  this->window.draw(teeOffBox);
  this->window.draw(hole);
}
