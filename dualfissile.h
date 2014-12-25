#ifndef DUALFISSILE_H
#define DUALFISSILE_H

#include <string>
#include "normal.h"


namespace world_of_particles {
  class DualFissile : public Normal {
  public:
    DualFissile(MultiVal*, string, Position*, Direction*, double, double);
    void draw();
    void save();
  };
}

#endif //DUALFISSILE_H