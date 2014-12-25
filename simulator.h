#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <cstdlib>

#include "namegen.h"
#include "particle.h"
#include "normal.h"
#include "photonic.h"
#include "dual.h"
#include "fissile.h"
#include "dualfissile.h"

namespace world_of_particles {
  class Simulator {
  private:
    NameGen *gen;
    vector<Particle*> particles;
    int p_num, itterations;
    MultiVal size;
    void init(auto&);
  public:
    Simulator(int, int, int, int);
    void show();
    ~Simulator();
  };
}

#endif // SIMULATOR_H
