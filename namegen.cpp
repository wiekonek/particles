#include "namegen.h"
#include <sstream>

using world_of_particles::NameGen;
using std::string;

NameGen::NameGen() : number(0) {
}

string NameGen::genName() {
  std::ostringstream tmp;
  tmp << "p" << number++;
  return tmp.str();
}