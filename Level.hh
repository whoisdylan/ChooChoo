#ifndef LEVEL_GUARD
#define LEVEL_GUARD

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum TERRAIN_TYPE {GRASS, WALL, TEEOFF, HOLE};

using namespace std;
using namespace sf;

class Level {
  public:
    Vector2<int> teeOff;
    Vector2<int> hole;
    vector< vector<TERRAIN_TYPE> > map;
    Level(Vector2<int> teeOff, Vector2<int> hole, vector< vector<TERRAIN_TYPE> >map) {
      this->teeOff = teeOff;
      this->hole = hole;
      this->map = map;
    }
};

#endif
