#include "particle.h"

using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;
using std::ofstream;

Particle::Particle(MultiVal* max, string name, Position* position, Direction* direction, double r, double m) {
  this->max = new MultiVal(max->get_x(), max->get_y());
  this->name = name;
  this->position = new Position(position);
  this->direction = new Direction(direction);
  this->r = r;
  this->m = 0;
}

Particle::~Particle() {
  delete position;
  delete direction;
}

void Particle::draw(string type) {
  cout<<name<<"\t"<<type<<"\t"<<position->get_x()<<"\t"<<position->get_y()<<"\t"<< direction->get_x() << "\t" << direction->get_y() << "\t" <<r;
}

void Particle::save(string type, double add) {
  ofstream file;
  file.open("output.txt", std::ios::out | std::ios::app);
//   file.precision(20);
  file << name << "\t" << type << "\t" << position->get_x() << "\t" << position->get_y() << "\t" << r << "\t" << add << "\n";
  file.close();
}


