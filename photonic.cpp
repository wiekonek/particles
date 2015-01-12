#include "photonic.h"

using world_of_particles::Photonic;
using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;

Photonic::Photonic(MultiVal* max, string name, Position* position, Direction* direction, double r):
  Particle(max, name, position, direction, r, 0) {};

void Photonic::draw() {
  Particle::draw("PHOTONIC");
  std::cout<<"\n";
}

void Photonic::save() {
  Particle::save("PH", 0);
}

void Photonic::move(vector< Particle* >) {
  if( position->get_x() < 0 || position->get_x() > max->get_x() ) direction->invert_x();
  if( position->get_y() < 0 || position->get_y() > max->get_y() ) direction->invert_y();
  position->update(direction);
}
