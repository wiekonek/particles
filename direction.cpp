#include "direction.h"

using world_of_particles::Direction;

Direction::Direction(Direction* other) {
  *this = *other;
}

void Direction::randomize() {
  x = (rand() % 101) / 100.0;
  y = (rand() % 101) / 100.0;
}
