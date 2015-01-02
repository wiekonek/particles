#include "direction.h"

using world_of_particles::Direction;

Direction::Direction(Direction* other) {
  *this = *other;
}

Direction::Direction(const Direction& direction) {
  x = direction.x;
  y = direction.y;
}

Direction::Direction(MultiVal multi) {
 x = multi.get_x();
 y = multi.get_y();
}


Direction Direction::positive() const {
  if( x > 0 )
    return y > 0 ? new Direction( x, y ) : new Direction( x, -y );
  else
    return y > 0 ? new Direction( -x, y) : new Direction( -x, -y);
}

void Direction::randomize() {
  x = (rand() % 101) / 100.0;
  y = (rand() % 101) / 100.0;
}

void Direction::invert_x() {
  x = -x;
}

void Direction::invert_y() {
  y = -y;
}