#ifndef NAMEGEN_H
#define NAMEGEN_H

#include <string>

using std::string;

namespace world_of_particles {
  class NameGen
  {
  private:
    int number;
  public:
    NameGen();
    string genName();
  };
}
#endif // NAMEGEN_H
