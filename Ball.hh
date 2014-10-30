#ifndef BALL_GUARD
#define BALL_GUARD

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr int windowWidth{800}, windowHeight{600};
constexpr float ballRadius{10.f};

class Ball {
  public:
    CircleShape shape;
    RectangleShape aimer;
    Ball (float mX, float mY) {
      shape.setPosition(mX, mY);
      shape.setRadius(ballRadius);
      shape.setFillColor(Color::Green);
      shape.setOrigin(ballRadius, ballRadius);
      aimer.setPosition(mX, mY);
      aimer.setSize(Vector2f(50, 4));
      aimer.setFillColor(Color::Cyan);
      aimer.setOrigin(0, 2);
    }
};

#endif
