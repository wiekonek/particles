#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "simulator.h"
#include "direction.h"

#define HEIGHT 10
#define WIDTH 10

using std::cout;
using world_of_particles::Simulator;
using world_of_particles::Direction;

int main(int argc, char* argv[]) {
  srand( std::time( NULL ) );
  
  Simulator *simulator = new Simulator(WIDTH, HEIGHT, 4, 100);
  simulator->run_simulation();
  
  return 0;
}