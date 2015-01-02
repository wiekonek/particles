#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <cstdlib>
#include <fstream>

#include "namegen.h"
#include "particle.h"
#include "normal.h"
#include "photonic.h"
#include "dual.h"
#include "fissile.h"
#include "dualfissile.h"

using std::ofstream;

namespace world_of_particles {
  class Simulator {
  private:
    ofstream file;
    NameGen *gen;
    vector<Particle*> particles;
    int p_num, itterations;
    MultiVal *size;
    void init(auto&);
    vector< vector<Particle*> > colDetector();
    void save(int);
    void show();
  public:
    Simulator(int, int, int, int);
    void run_simulation();
    ~Simulator();
  };
}

#endif // SIMULATOR_H
