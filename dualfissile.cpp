#include "dualfissile.h"

using world_of_particles::DualFissile;
using world_of_particles::Position;
using world_of_particles::Direction;


DualFissile::DualFissile(string name, Position* position, Direction* direction, double r, double m):
  Normal(name, position, direction, r, m) {
}

void DualFissile::draw() {
  Particle::draw("DF");
  std::cout<<"\t"<<m<<"\n";
}

