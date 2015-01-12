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
    if( typeid ( *particle ).name() == typeid ( Dual ).name() || typeid ( *particle ).name() == typeid ( DualFissile ).name() )
      d = true;
  }
  
}

double* Collision::new_div(double sum){
  double *ret = new double[other];
  for(int i = 0; i < other; i++) 
    ret[i] = sum/other;

  return ret;
}

void Collision::update() {
  Direction dir;
  Position pos;
  const int num = colide_particles.size();
  int i = 0;
  double *tr = new_div(r), *tm = new_div(m), mm;
  Fissile *fis;
  cout<<tr[0]<<"\n";

  for(Particle* particle : colide_particles) {
    if( typeid ( *particle ) == typeid ( Photonic ) ) {
      particle->updateDirection();
    }else {
      if(other > 1) {
	particle->updateDirection();
	particle->set_m(tm[i]);
	if(d)
	 particle->set_r(tr[i]);
	
	if( typeid ( *particle ) == typeid ( Fissile ) || typeid ( *particle ) == typeid ( DualFissile ) ) {
	  mm = particle->get_m()/2;
	  particle->set_m(mm);
	  particle->set_r(( rand()%9 + 1 ) / 20.0);
	  fis = new Fissile( particle->get_size(), gen->genName(), &particle->get_position(), &particle->get_direction(), ( rand()%9 + 1 ) / 20.0, mm );
	  fis->updateDirectionX();
	  fis->move(particles);
	  particle->updateDirection();
	  particle->move(particles);
	  
	  particles.push_back( fis );
	}
      }
      i++;
    }
  }
  
  delete tm;
  
  for(auto itt = particles.begin(); itt < particles.end(); itt++) {
    if( typeid(*(*itt)) != typeid(Photonic) && (*itt)->get_m() < 0.1) {
      particles.erase(itt);
    }
    
  }
}
