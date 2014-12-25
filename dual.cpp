#include "dual.h"

using world_of_particles::Dual;
using world_of_particles::Position;
using world_of_particles::Direction;


Dual::Dual(string name, Position* position, Direction* direction, double r, double m):
  Normal(name, position, direction, r, m) {
}

void Dual::draw() {
  Particle::draw("DUAL");
  std::cout<<"\t"<<m<<"\n";
}

