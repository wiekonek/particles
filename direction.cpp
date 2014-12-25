#include "direction.h"

using world_of_particles::Direction;

Direction::Direction(Direction* other) {
  *this = *other;
}

void Direction::randomize() {
  x = (rand() % 101) / 10.0;
  y = (rand() % 101) / 10.0;
}

void Direction::invert_x() {
  x = -x;
}

void Direction::invert_y() {
  y = -y;
}
