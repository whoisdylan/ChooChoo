#ifndef INPUT__GUARD
#define INPUT__GUARD

#include <SFML/Window.hpp>
#include "Engine.hh"

class Input {
  public:
    static void update(Engine *);
};

#endif
