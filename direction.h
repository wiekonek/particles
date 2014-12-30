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
    bool operator< (const Direction&) const;
    Direction operator+ (const Direction&) const;
    Direction operator- (const Direction&) const;
    Direction operator* (const Direction&) const;
    Direction operator* (const int&) const;
    void invert_x();
    void invert_y();
    Direction* positive();
    void randomize();
  };
  
  Direction operator- (const int&, Direction&);
}

#endif // DIRECTION_H
