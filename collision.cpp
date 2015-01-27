#include <typeinfo>
#include "collision.h"

using world_of_particles::Collision;
using world_of_particles::Particle;
using world_of_particles::Normal;
using world_of_particles::Photonic;
using world_of_particles::Dual;
using world_of_particles::Fissile;
using world_of_particles::DualFissile;
using world_of_particles::Position;
using world_of_particles::Direction;
using world_of_particles::NameGen;
using std::cout;

Collision::Collision( vector<Particle*>& particles, NameGen* gen, vector<Particle*> colide_particles ) : particles(particles), gen(gen), colide_particles(colide_particles) {
  m = r = 0;
  d = false;
  other = 0;
  for(Particle* particle : colide_particles ) {
    if( typeid ( *particle ) != typeid ( Photonic ) ) {
      m += particle->get_m();
      r += particle->get_r();
      other++;
    }
    if( d != true && typeid ( *particle ).name() == typeid ( Dual ).name() || typeid ( *particle ).name() == typeid ( DualFissile ).name() )
      d = true;
  }
  
}

double* Collision::new_div(double sum, double max){
  double *ret = new double[other];
  double add;
  int random;
  for( int i = 0; i < other; i++ )
    ret[i] = 0;
  
  for( int i = 0; i < other*30; i++ ) { 
    add = sum * ( (rand() % 100) / 100.0 );  
    if( ret[random = rand() % other] + add < max) {
      ret[random] += add; 
      sum -= add;
    }
  }
  return ret;
}

void Collision::update() {

  const int num = colide_particles.size();
  int i = 0;
  double *tr = new_div(r, 0.5), *tm = new_div(m, 1), mm;
  Particle *part;
  Direction *dir = new Direction(colide_particles[0]->get_direction());
  for(Particle* particle : colide_particles) {
    if( typeid ( *particle ) == typeid ( Photonic ) ) {
      particle->updateDirection();
    }else {
      if(other > 1) {
	
	particle->set_m(tm[i]);

	if( i < num-1 && typeid ( colide_particles[i+1] ) != typeid ( Photonic ) ) {
	  particle->updateDirection(*(new Direction(colide_particles[i+1]->get_direction())) );
	} else if( i == num-1 && typeid ( colide_particles[0] ) != typeid ( Photonic ) ){
	  particle->updateDirection(*dir);
	}
	particle->move(particles);
	if(d)
	 particle->set_r(tr[i]);
	
	if( typeid ( *particle ) == typeid ( Fissile ) || typeid ( *particle ) == typeid ( DualFissile ) ) {
	  mm = particle->get_m()/2;
	  particle->set_m(mm);
	  particle->set_r(( rand()%9 + 1 ) / 20.0);
	  part = new Normal( particle->get_size(), gen->genName(), &particle->get_position(), &particle->get_direction(), ( rand()%9 + 1 ) / 20.0, mm );

	  
	  particle->updateDirection();

	  
	  particles.push_back( part );
	}
      }
      
    }
    i++;
  }
  
  delete tm;
  
  for(auto itt = particles.begin(); itt < particles.end(); itt++) {
    if( typeid(*(*itt)) != typeid(Photonic) && (*itt)->get_m() < 0.01) {
      particles.erase(itt);
    }
    
  }
}
