#include "Level.hh"

class Level1 : public Level {
public:
  Level1() {
    this->teeOff = Vector2<int>(9,5);
    this->hole = Vector2<int>(0,5);
    this->map = vector< vector<TERRAIN_TYPE> >(10, vector<TERRAIN_TYPE>(10, GRASS));
    this->map[this->teeOff.x][this->teeOff.y] = TEEOFF;
    this->map[this->hole.x][this->hole.y] = HOLE;
    for (int row = 0; row < this->map.size(); row++) {
      this->map[row][3] = WALL;
      this->map[row][7] = WALL;
    }
    printMap();
  }
};
