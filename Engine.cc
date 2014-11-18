#include "Engine.hh"
#include <vector>
#include <math.h>
#include <iostream>
#include "Input.hh"
#include "RenderUtil.hh"
#include "Mesh.hh"
// #include "Level1.hh"
// #include "Ball.hh"
// #include "Window.hh"

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
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  settings.majorVersion = 3;
  settings.minorVersion = 3;
  gameWindow.create({windowWidth, windowHeight}, title, sf::Style::Default, settings);
  glewExperimental = GL_TRUE;
  glewInit();
  RenderUtil::initGraphics();
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
  game->init();
  sf::Clock clock;
  sf::Time unprocessedTime = sf::seconds(0);
  sf::Time frameCounter = sf::seconds(0);
	int frames = 0;

  while (isRunning) {
    bool shouldRender = false;
    sf::Time elapsedTime = clock.restart();

		unprocessedTime += elapsedTime;
		frameCounter += elapsedTime;

    if (frameCounter.asSeconds() >= 1.0) {
      cout << frames << " fps" << endl;
      frames = 0;
      frameCounter = sf::seconds(0);
    }
    while (unprocessedTime > frameTime) {
      shouldRender = true;

      Input::update(this);
      // game->Input((float) frameTime);
      // game->Update((float) frameTime);
      
      unprocessedTime -= frameTime;
    }
    if (shouldRender) {
      render();
      frames++;
    } else {
      sf::sleep(sf::milliseconds(1));
    }
  }
}

void Engine::render() {
  RenderUtil::clearScreen();
  game->render();
  gameWindow.display();
  
}
