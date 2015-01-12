#ifndef DIRECTION_H
#define DIRECTION_H

#include "multival.h"
#include <iostream>

using std::ostream;

namespace world_of_particles {
  class Direction : public MultiVal {
  public:
    Direction() : MultiVal() {}
    Direction(double one, double two) : MultiVal(one, two) {}
    Direction(Direction*);
    Direction(const Direction&);
    Direction(MultiVal);

    void invert_x();
    void invert_y();
    Direction positive() const;
    void randomize();
  };
}

#endif // DIRECTION_H
