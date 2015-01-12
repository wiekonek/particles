#include "normal.h"
#include <iostream>
using world_of_particles::Normal;
using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;
using std::string;

Normal::Normal( MultiVal* max, string name, Position* position, Direction* direction, double r, double m ):
  Particle( max, name, position, direction, r, m ) {
}

void Normal::draw() {
  Particle::draw( "NORMAL" );
  std::cout << "\t" << m << "\n";
}

void Normal::save() {
  Particle::save( "NO", m );
}

void Normal::move( vector<Particle*> particles ) {
  cout<< "\ndir: " << direction->get_x() << " : " << direction->get_y() << "\n";
  for( auto particle : particles ) {
    if(particle->get_name() != name) {
    Direction k( particle->get_position() - *position );
    Direction maxi( std::max(Direction(2,2)-k.positive(), MultiVal(0,0)) * m * particle->get_m() * k );
    cout<< "max: " << maxi.get_x() << " : " << maxi.get_y() << "\n";
    *direction = *direction + (std::max(Direction(2,2)-k.positive(), MultiVal(0,0)) * m * particle->get_m() * k * 0.001);
    }
  }  
  if( position->get_x() < 0 || position->get_x() > max->get_x() ) direction->invert_x();
  if( position->get_y() < 0 || position->get_y() > max->get_y() ) direction->invert_y();
  position->update(direction);
}



