#include <vector>
#include <math.h>
#include <iostream>
#include "Engine.hh"
#include "Input.hh"
// #include "Level1.hh"
// #include "Ball.hh"
// #include "Window.hh"

#define PI 3.14159265

using namespace std;
// using namespace sf;

Engine::Engine(unsigned int windowWidth, unsigned int windowHeight, double framerate, Game *game) :
  isRunning(false),
  windowWidth(windowWidth),
  windowHeight(windowHeight),
  frameTime (sf::seconds(1.0/framerate)),
  game (game) {
}

Engine::~Engine() {
  //Window::dispose();
}

void Engine::createWindow(const string& title) {
  gameWindow.create({windowWidth, windowHeight}, title);
}

void Engine::start() {
  if (isRunning) {
    return;
  } else {
    Engine::run();
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

      Input::update(this);
      // game->Input((float) frameTime);
      // game->Update((float) frameTime);
      
      unprocessedTime -= frameTime;
    }
    if (render) {
      // game->render();
      // Window::render();
      frames++;
    } else {
      sf::sleep(sf::milliseconds(1));
    }
  }
}
