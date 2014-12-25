#include "simulator.h"

using world_of_particles::Simulator;
using world_of_particles::NameGen;
using world_of_particles::Particle;
using world_of_particles::Normal;
using world_of_particles::Photonic;
using world_of_particles::Dual;
using world_of_particles::Fissile;
using world_of_particles::DualFissile;
using world_of_particles::Position;
using world_of_particles::Direction;
using std::cout;

void Simulator::init(auto& particle) {
  Position *new_position = new Position();
  Direction *new_direction = new Direction();
  new_position->randomize(size.get_x(), size.get_y());
  new_direction->randomize();
  
  switch(rand()%5) {
    case 0: particle = new Normal(gen->genName(), new_position, new_direction, 1, 2);
    break;
    case 1: particle = new Photonic(gen->genName(), new_position, new_direction, 1);
    break;
    case 2: particle = new Dual(gen->genName(), new_position, new_direction, 1, 2);
    break;
    case 3: particle = new Fissile(gen->genName(), new_position, new_direction, 1, 2);
    break;
    case 4: particle = new DualFissile(gen->genName(), new_position, new_direction, 1, 2);
    break;
  }

  delete new_position;
  delete new_direction;
}


Simulator::Simulator( int x, int y, int p_num, int itterations) :  size(x, y), p_num(p_num), itterations(itterations) {
  
  gen = new NameGen();
  particles.resize(p_num);
  
  for(auto& particle : particles)
    init(particle);

}


Simulator::~Simulator() {
  for(Particle* particle : particles)
    delete particle;
  delete gen;
  particles.resize(0);
}

void Simulator::show() {
  cout<<"NAME\tTYPE\tX\tY\tR\tM\n";
  for(Particle* particle : particles)
    particle->draw();
}



