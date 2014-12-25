#ifndef PHOTONIC_H
#define PHOTONIC_H

#include "particle.h"

namespace world_of_particles {
  class Photonic : public Particle {
  public:
    Photonic(string, Position*, Direction*, double);
    void draw();
    void update();
  };
}
#endif // PHOTONIC_H
