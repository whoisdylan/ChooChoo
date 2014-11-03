#include <vector>
#include <math.h>
#include <iostream>
#include "Ball.hh"
#include "Window.hh"
#include "Level1.hh"

#define PI 3.14159265

using namespace std;
using namespace sf;

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
  baller::Window *window = new baller::Window;
	// RenderWindow window{{windowWidth, windowHeight}, "Baller"};
	window->window.setFramerateLimit(60);

  Level *currentLevel = new Level1;

	Ball ball(100*currentLevel->teeOff.x, 100*currentLevel->teeOff.y);
  vector<float> velocity(2,0);


	while (true) {
		sf::Event event;
		window->window.pollEvent(event);
		window->window.clear(Color::Black);
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

    window->drawCourse(currentLevel->teeOff, currentLevel->hole);
		window->window.draw(ball.shape);
    window->window.draw(ball.aimer);
		window->window.display();
	}
	return 0;
}
