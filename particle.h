#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <string>
#include <iostream>

#include "position.h"
#include "direction.h"

using std::vector;
using std::string;

namespace world_of_particles {
  class Particle {
  protected:
    string name;
    Position *position;
    Direction *direction;
    double r;
  public:
    Particle(string, Position*, Direction*, double);
    virtual ~Particle();
    virtual void draw(string);
    virtual void draw() = 0;
    virtual void update() = 0;
  };
}

#endif // PARTICLE_H
