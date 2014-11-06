#include "Ball.hh"

Ball::Ball (float mX, float mY) {
  shape.setPosition(mX, mY);
  shape.setRadius(ballRadius);
  shape.setFillColor(sf::Color::Blue);
  shape.setOutlineColor(sf::Color::White);
  shape.setOutlineThickness(2);
  shape.setOrigin(ballRadius, ballRadius);
  aimer.setPosition(mX, mY);
  aimer.setSize(sf::Vector2f(50, 4));
  aimer.setFillColor(sf::Color::Cyan);
  aimer.setOrigin(0, 2);
}
