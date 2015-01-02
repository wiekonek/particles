#include "particle.h"
#include <math.h>
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
  this->m = m;
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

double Particle::distanceTo(Particle* other) {
  double x1 = position->get_x();
  double y1 = position->get_y();
  double x2 = other->position->get_x();
  double y2 = other->position->get_y();
  return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}



