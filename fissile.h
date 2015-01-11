#ifndef FISSILE_H
#define FISSILE_H

#include <string>
#include "normal.h"


namespace world_of_particles {
  class Fissile : public Normal {
  public:
    Fissile(MultiVal*, string, Position*, Direction*, double, double);
    void draw();
    void updateDirectionX();
    void updateDirectionY();
    void save();
  };
}

#endif //FISSILE_H