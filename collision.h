#ifndef COLLISION_H
#define COLLISION_H

#include <vector>


#include "particle.h"
#include "normal.h"
#include "photonic.h"
#include "dual.h"
#include "fissile.h"
#include "dualfissile.h"
#include "namegen.h"

namespace world_of_particles {
  
  class Collision
  {
  private:
    NameGen *gen;
    vector<Particle*>& particles;
    vector<Particle*> colide_particles;
    double m;
    double r;
    bool d;
    int other;
    
    double* new_div(double);
  public:
    Collision(vector<Particle*>&, NameGen*, vector<Particle*> );
    void update();
  };
}

#endif // COLLISION_H
