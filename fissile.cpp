#include "fissile.h"

using world_of_particles::Fissile;
using world_of_particles::Position;
using world_of_particles::Direction;


Fissile::Fissile(MultiVal* max, string name, Position* position, Direction* direction, double r, double m):
  Normal(max, name, position, direction, r, m) {
}

void Fissile::draw() {
  Particle::draw("FISSILE");
  std::cout<<"\t"<<m<<"\n";
}

void Fissile::save() {
  Particle::save("FI", m);
}

void Fissile::updateDirectionX() {
  direction->invert_x();
}

void Fissile::updateDirectionY() {
  direction->invert_y();
}
