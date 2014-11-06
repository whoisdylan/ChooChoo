#include <vector>
#include <math.h>
#include <iostream>
#include "Engine.hh"
#include "Ball.hh"
#include "Window.hh"
// #include "Input.hh"
#include "Level1.hh"

#define PI 3.14159265

using namespace std;
// using namespace sf;

Engine::Engine(int windowWidth, int windowHeight, double framerate, Game *game) :
  isRunning(false),
  windowWidth(windowWidth),
  windowHeight(windowHeight),
  frameTime (sf::seconds(1.0/framerate)),
  game (game) {
}

Engine::~Engine() {
  Window::dispose();
}

void Engine::createWindow(const string& title) {
  Window::create(windowWidth, windowHeight, title);
}

void Engine::start() {
  if (isRunning) {
    return;
  } else {
    run();
  }
}

void Engine::stop() {
  if (!isRunning) {
    return;
  } else {
    isRunning = false;
  }
}

void Engine::run() {
  isRunning = true;
  // game->init();
  sf::Clock clock;
  sf::Time unprocessedTime = sf::seconds(0);
  sf::Time frameCounter = sf::seconds(0);
	int frames = 0;

  while (isRunning) {
    bool render = false;
    sf::Time elapsedTime = clock.restart();

		unprocessedTime += elapsedTime;
		frameCounter += elapsedTime;

    if (frameCounter.asSeconds() >= 1.0) {
      cout << frames << " fps" << endl;
      frames = 0;
      frameCounter = sf::seconds(0);
    }
    while (unprocessedTime > frameTime) {
      render = true;
      if (Window::isCloseRequested()) {
        stop();
      }

      Input::update();
      // game->Input((float) frameTime);
      // game->Update((float) frameTime);
      
      unprocessedTime -= frameTime;
    }
    if (render) {
      // game->render();
      Window::render();
      frames++;
    } else {
      sf::sleep(sf::milliseconds(1));
    }
  }
}

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
