#ifndef FISSILE_H
#define FISSILE_H

#include <string>
#include "normal.h"


namespace world_of_particles {
  class Fissile : public Normal {
  public:
    Fissile(std::string, Position*, Direction*, double, double);
    void draw();
  };
}

#endif //FISSILE_H