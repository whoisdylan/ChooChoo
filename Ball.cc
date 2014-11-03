#include "Ball.hh"

Ball::Ball (float mX, float mY) {
  shape.setPosition(mX, mY);
  shape.setRadius(ballRadius);
  shape.setFillColor(Color::Blue);
  shape.setOutlineColor(Color::White);
  shape.setOutlineThickness(2);
  shape.setOrigin(ballRadius, ballRadius);
  aimer.setPosition(mX, mY);
  aimer.setSize(Vector2f(50, 4));
  aimer.setFillColor(Color::Cyan);
  aimer.setOrigin(0, 2);
}
