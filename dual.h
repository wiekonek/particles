#ifndef DUAL_H
#define DUAL_H

#include <string>
#include "normal.h"


namespace world_of_particles {
  class Dual : public Normal {
  public:
    Dual(std::string, Position*, Direction*, double, double);
    void draw();
  };
}

#endif //DUAL_H