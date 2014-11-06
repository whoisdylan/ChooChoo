#ifndef LEVEL_GUARD
#define LEVEL_GUARD

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

enum TERRAIN_TYPE {GRASS, WALL, TEEOFF, HOLE};

using namespace std;
// using namespace sf;

class Level {
public:
  sf::Vector2i teeOff;
  sf::Vector2i hole;
  vector< vector<TERRAIN_TYPE> > map;
  Level() {}
  Level(sf::Vector2i teeOff, sf::Vector2i hole, vector< vector<TERRAIN_TYPE> >map) {
    this->teeOff = teeOff;
    this->hole = hole;
    this->map = map;
  }
  void printMap() {
    for (int row = 0; row < (int) this->map.size(); row++) {
      for (int col = 0; col < (int) this->map[0].size(); col++) {
        cout << this->map[row][col] << " ";
      }
      cout << endl;
    }
  }
};

#endif
