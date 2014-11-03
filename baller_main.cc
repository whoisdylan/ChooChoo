#include <vector>
#include <math.h>
#include <iostream>
#include "Ball.hh"
#include "Level1.cc"

#define PI 3.14159265

using namespace std;
using namespace sf;

// struct Ball {
// 	CircleShape shape;
//   RectangleShape aimer;
// 	Ball (float mX, float mY) {
// 		shape.setPosition(mX, mY);
// 		shape.setRadius(ballRadius);
// 		shape.setFillColor(Color::Green);
// 		shape.setOrigin(ballRadius, ballRadius);
//     aimer.setPosition(mX, mY);
//     aimer.setSize(Vector2f(50, 4));
//     aimer.setFillColor(Color::Cyan);
// 		aimer.setOrigin(0, 2);
// 	}
// };

void handleMovement(vector<int> &velocity) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		velocity[0] -= 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		velocity[0] += 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		velocity[1] -= 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		velocity[1] += 1;
	}
}

float magnitude(const vector<float> &velocity) {
  return sqrt(velocity[0]*velocity[0]+velocity[1]*velocity[1]);
}

int handleAim() {
  int angleOffset = 0;
  if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
    angleOffset += 10;
  }
  if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
    angleOffset -= 10;
  }
  return angleOffset;
}

void handleForce(vector<float> &velocity) {
  static bool forceApplied = false;
  if (!forceApplied && Keyboard::isKeyPressed(Keyboard::Key::F)) {
    velocity = {10,10};
    forceApplied = true;
  } else if (magnitude(velocity) > 0) {
    velocity[0] -= 1;
    velocity[1] -= 1;
  } else {
    forceApplied = false;
  }
}

int main() {
	RenderWindow window{{windowWidth, windowHeight}, "Baller"};
	window.setFramerateLimit(60);

	Ball ball{ballRadius, windowHeight/2};
  vector<float> velocity(2,0);

  Level *currentLevel = new Level1;

	while (true) {
		sf::Event event;
		window.pollEvent(event);
		window.clear(Color::Black);
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
			break;
		}
    Vector2f currentPosition = ball.shape.getPosition();
    if (currentPosition.x >= windowWidth-ballRadius) {
      ball.shape.setPosition(ballRadius, windowHeight/2);
      ball.aimer.setPosition(ballRadius, windowHeight/2);
    }
		// handleMovement(velocity);
    int aimAngleOffset = handleAim();
    ball.aimer.rotate(aimAngleOffset);
    float aimAngle = ball.aimer.getRotation();
    handleForce(velocity);
    float xOffset = velocity[1]*cos(aimAngle*PI/180);
    float yOffset = velocity[0]*sin(aimAngle*PI/180);
		ball.shape.move(xOffset, yOffset);
		ball.aimer.move(xOffset, yOffset);

		window.draw(ball.shape);
    window.draw(ball.aimer);
		window.display();
	}
	return 0;
}
