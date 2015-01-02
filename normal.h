#ifndef NORMAL_H
#define NORMAL_H

#include "particle.h"

namespace world_of_particles {
  class Normal : public Particle {
  public:
    Normal(MultiVal*, string, Position*, Direction*, double, double);
    void draw();
    void save();
    void update();
    void move( vector<Particle*> particles );
  };
}

#endif // NORMAL_H
