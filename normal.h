#ifndef NORMAL_H
#define NORMAL_H

#include "particle.h"

namespace world_of_particles {
  class Normal : public Particle {
  protected:
    double m;
  public:
    Normal(MultiVal*, string, Position*, Direction*, double, double);
    void draw();
    void save();
    void update();
  };
}

#endif // NORMAL_H
