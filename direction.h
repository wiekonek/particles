#ifndef DIRECTION_H
#define DIRECTION_H

#include "multival.h"

namespace world_of_particles {
  class Direction : public MultiVal {
  public:
    Direction() : MultiVal() {};
    Direction(double one, double two) : MultiVal(one, two) {};
    Direction(Direction* direction);
    void invert_x();
    void invert_y();
    void randomize();
  };
}

#endif // DIRECTION_H
