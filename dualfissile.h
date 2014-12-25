#ifndef DUALFISSILE_H
#define DUALFISSILE_H

#include <string>
#include "normal.h"


namespace world_of_particles {
  class DualFissile : public Normal {
  public:
    DualFissile(std::string, Position*, Direction*, double, double);
    void draw();
  };
}

#endif //DUALFISSILE_H