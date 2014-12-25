#include "photonic.h"

using world_of_particles::Photonic;
using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;

Photonic::Photonic(string name, Position* position, Direction* direction, double r):
  Particle(name, position, direction, r) {};
  
void Photonic::update(){
}

void Photonic::draw(){
  Particle::draw("PHOTONIC");
  std::cout<<"\n";
}
