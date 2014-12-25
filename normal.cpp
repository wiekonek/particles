#include "normal.h"

using world_of_particles::Normal;
using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;
using std::string;

Normal::Normal(string name, Position* position, Direction* direction, double r, double m):
  Particle(name, position, direction, r), m(m) {
}

void Normal::update() {
}

void Normal::draw() {
  Particle::draw("NORMAL");
  std::cout<<"\t"<<m<<"\n";
}
