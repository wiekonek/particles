#include "simulator.h"
#include "collision.h"
#include <typeinfo>

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
using world_of_particles::Collision;
using std::cout;

void Simulator::init( auto& particle ) {
  Position *new_position = new Position();
  Direction *new_direction = new Direction();
  new_position->randomize( size->get_x(), size->get_y() );
  new_direction->randomize();
  double m = ( rand()%9 + 1 )  / 10.0; 				//m (0, 1)
  double r = ( rand()%9 + 1 ) / 20.0;				//r (0, 0.5)

  switch( rand()%5 ) {
    case 0: particle = new Normal( size, gen->genName(), new_position, new_direction, r, m);
    break;
    case 1: particle = new Photonic(size, gen->genName(), new_position, new_direction, r);
    break; 
    case 2: particle = new Dual( size, gen->genName(), new_position, new_direction, r, m );
    break;
    case 3: particle = new Fissile( size, gen->genName(), new_position, new_direction, r, m );
    break;
    case 4: particle = new DualFissile( size, gen->genName(), new_position, new_direction, r, m );
    break;
  }

  delete new_position;
  delete new_direction;
}

Simulator::Simulator( int x, int y, int p_num, int itterations ) :  p_num( p_num ), itterations( itterations ) {
  size = new MultiVal( x, y );
  gen = new NameGen();
  particles.resize( p_num );
  
  for( auto& particle : particles )
    init( particle );
}

Simulator::~Simulator() {
  for( Particle* particle : particles )
    delete particle;
  delete gen;
  delete size;
  particles.resize( 0 );
}

void Simulator::show() {
  cout << "\nNAME\tTYPE\tX\tY\tvX\tvY\tR\tM\n";
  for( Particle* particle : particles )
    particle->draw();
}

void Simulator::save( int i ) {
  file.open( "output.txt", std::ios::out | std::ios::app );
  file << "t" << i << "\n";
  file.close();
  for( Particle* particle : particles )
    particle->save();
  
  file.open( "output.txt", std::ios::out | std::ios::app );
  file << "\n" << "k" << i << "\n";
  for(auto line : collisions) {
    for(Particle* particle : line)
      file << particle->get_name() << "\t";
    file << "\n";
  }
  file << "\n";
  file.close();
}

bool colide( Particle* p1, Particle* p2 ) {
  return ( p1->distanceTo(p2) <= p1->get_r()+p2->get_r() ) ? 1 : 0;
}

vector< vector<Particle*> > Simulator::colDetector() {
  vector< vector<Particle*> > result;
  vector<bool> colid( particles.size(), false );
  int i = 0, j = 0;
  for( Particle* p1 : particles ) {
    j = 0;
    for( Particle* p2 : particles ) {
      if( i != j && colide(p1, p2) ) {
	if( !colid[i] && !colid[j] ) {
	  vector<Particle*> vec(0);
	  vec.push_back(p1);
	  vec.push_back(p2);
	  result.push_back(vec);
	} else if ( !colid[i] || !colid[j] ) {
	  for(auto& line : result) {
	    for(Particle* particle : line) {
	     if(particle == p1)
	       line.push_back(p2);
	     else if(particle == p2)
	       line.push_back(p1);
	    }
	  }
	}
	colid[i] = true;
	colid[j] = true;
      }
      j++;
    }
    i++;
  }
  return result;
}

void Simulator::update() {
  Collision *collision;
  for(auto& line : collisions) {
    collision = new Collision(particles, gen, line );
    collision->update();
    delete collision;
  }
}


void Simulator::run_simulation() {
  file.open( "output.txt", std::ios::out | std::ios::trunc );
  file.close();
  for( int i = 1; i <= itterations; i++ ) {
    collisions = colDetector();
    update();
    for( auto& particle : particles )
      particle->move( particles );
    save( i );
    //show();
  }
}