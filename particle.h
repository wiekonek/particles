#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "position.h"
#include "direction.h"
#include "multival.h"
#include "fstream"

using std::stringstream;
using std::string;
using std::cout;
using std::vector;

namespace world_of_particles {
  class Particle {
  protected:
    string name;
    Position *position;
    Direction *direction;
    MultiVal *max;
    double r;
  public:
    Particle(MultiVal*, string, Position*, Direction*, double);
    virtual ~Particle();
    virtual void move();
    virtual void draw(string);
    virtual void save(string, double);
    virtual void save() = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
  };
}

#endif // PARTICLE_H
