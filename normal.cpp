#include "normal.h"

using world_of_particles::Normal;
using world_of_particles::Particle;
using world_of_particles::Position;
using world_of_particles::Direction;
using std::string;

Normal::Normal( MultiVal* max, string name, Position* position, Direction* direction, double r, double m ):
  Particle( max, name, position, direction, r, m ) {
}

void Normal::update() {
}

void Normal::draw() {
  Particle::draw( "NORMAL" );
  std::cout << "\t" << m << "\n";
}

void Normal::save() {
  Particle::save( "NO", m );
}

void Normal::move( vector<Particle*> particles ) {
  if( position->get_x() < 0 || position->get_x() > max->get_x() ) direction->invert_x();
  if( position->get_y() < 0 || position->get_y() > max->get_y() ) direction->invert_y();

  for( auto particle : particles ) {
    Direction k( particle->get_direction() - direction );
    *direction = *direction + std::max( 100-*(k.positive()), Direction( 0, 0 ) ) * m * particle->get_m() * k;
  }
  position->update(direction);
}



