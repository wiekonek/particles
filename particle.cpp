#include "particle.h"

using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;
using std::ofstream;

Particle::Particle(MultiVal* max, string name, Position* position, Direction* direction, double r) {
  this->max = new MultiVal(max->get_x(), max->get_y());
  this->name = name;
  this->position = new Position(position);
  this->direction = new Direction(direction);
  this->r = r;
}

Particle::~Particle() {
  delete position;
  delete direction;
}

void Particle::draw(string type) {
  cout<<name<<"\t"<<type<<"\t"<<position->get_x()<<"\t"<<position->get_y()<<"\t"<<r;
}

void Particle::save(string type, double add) {
  ofstream file;
  file.open("output.txt", std::ios::out | std::ios::app);
//   file.precision(20);
  file << name << "\t" << type << "\t" << position->get_x() << "\t" << position->get_y() << "\t" << r << "\t" << add << "\n";
  file.close();
}


void Particle::move() {
  if(position->get_x() < 0 || position->get_x() > max->get_x()) direction->invert_x();
  if(position->get_y() < 0 || position->get_y() > max->get_y()) direction->invert_y();
  position->update(direction);
}


