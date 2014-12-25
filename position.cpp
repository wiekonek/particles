#include "position.h"

using world_of_particles::Position;

Position::Position(Position* other) {
  *this = *other;
}

void Position::randomize(int x_max, int y_max) {
  x = rand() % (x_max + 1);
  y = rand() % (y_max + 1);
}
