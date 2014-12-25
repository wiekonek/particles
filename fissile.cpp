#include "fissile.h"

using world_of_particles::Fissile;
using world_of_particles::Position;
using world_of_particles::Direction;


Fissile::Fissile(string name, Position* position, Direction* direction, double r, double m):
  Normal(name, position, direction, r, m) {
}

void Fissile::draw() {
  Particle::draw("FISSILE");
  std::cout<<"\t"<<m<<"\n";
}

