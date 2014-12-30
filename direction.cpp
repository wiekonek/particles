#include "direction.h"

using world_of_particles::Direction;

Direction::Direction(Direction* other) {
  *this = *other;
}

Direction::Direction(const Direction& direction) {
  x = direction.x;
  y = direction.y;
}

bool Direction::operator < (const Direction& direction) const {
  return ( this->x+this->y < direction.x+direction.y ) ? true : false ;
}

Direction world_of_particles::operator-(const int& a, Direction& direction) {
  return Direction( a-direction.get_x(), a-direction.get_y() );
}

Direction Direction::operator+(const Direction& direction) const {
  return Direction( x+direction.x, y+direction.y );
}

Direction Direction::operator-(const Direction& direction) const {
  return Direction( x-direction.x, y-direction.y );
}

Direction Direction::operator*(const int& a) const {
  return Direction( a*this->x, a*this->y );
}

Direction Direction::operator*(const Direction& d) const {
  return Direction( this->x*d.x, this->y*d.y );
}

Direction* Direction::positive() {
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