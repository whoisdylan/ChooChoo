#ifndef BALL_GUARD
#define BALL_GUARD

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr float ballRadius{10.f};

class Ball {
  public:
    CircleShape shape;
    RectangleShape aimer;
    Ball (float, float);
};

#endif
