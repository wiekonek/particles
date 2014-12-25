//normal , dual , fissile , dual_fissile  lub photonic

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "simulator.h"

#define HEIGHT 640
#define WIDTH 480

using std::cout;
using world_of_particles::Simulator;


int main(int argc, char* argv[]) {
  srand( std::time( NULL ) );
  
  Simulator *simulator = new Simulator(WIDTH, HEIGHT, 25, 100);
  simulator->show();
  
  return 0;
}
