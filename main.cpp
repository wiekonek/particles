//normal , dual , fissile , dual_fissile  lub photonic

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "simulator.h"

#define HEIGHT 480
#define WIDTH 640

using std::cout;
using world_of_particles::Simulator;


int main(int argc, char* argv[]) {
  srand( std::time( NULL ) );
  
  Simulator *simulator = new Simulator(WIDTH, HEIGHT, 4, 10);
  simulator->run_simulation();
  
  return 0;
}
