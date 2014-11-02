#include "Level.hh"

class Level1 : Level {
  public:
    Level1() {
      Vector2<int> level1TeeOff(9,5);
      Vector2<int> level1Hole(0,5);
      vector< vector<TERRAIN_TYPE> > level1Map(10, vector<TERRAIN_TYPE>(10, GRASS));
      level1Map[level1TeeOff.x][level1Hole.y] = TEEOFF;
      level1Map[level1Hole.x][level1Hole.y] = HOLE;
      for (int row = 0; row < level1Map.size(); row++) {
        Level1Map[row][3] = WALL;
        Level1Map[row][7] = WALL;
      }
      Level(teeOff, hole, level1Map);
    }
};
