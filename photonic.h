#ifndef PHOTONIC_H
#define PHOTONIC_H

#include "particle.h"

namespace world_of_particles {
  class Photonic : public Particle {
  public:
    Photonic(MultiVal*, string, Position*, Direction*, double);
    void draw();
    void save();
    void update();
    void move( vector<Particle*> );
  };
}
#endif // PHOTONIC_H
