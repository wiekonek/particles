#include "position.h"

using world_of_particles::Position;
using world_of_particles::Direction;

Position::Position(Position* other) {
  *this = *other;
}

void Position::randomize(int x_max, int y_max) {
  x = rand() % (x_max + 1);
  y = rand() % (y_max + 1);
}

void Position::update(Direction* direction) {
  x+=direction->get_x();
  y+=direction->get_y();
}

