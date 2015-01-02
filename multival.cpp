#include "multival.h"

MultiVal::MultiVal(): x(0), y(0) {}

MultiVal::MultiVal(double x, double y): x(x), y(y) {}

bool MultiVal::operator<(const MultiVal& other) const {
  return (this->x < other.x && this->y < other.y) ? true : false;
}

MultiVal MultiVal::operator+(const MultiVal& other) const {
  return MultiVal(this->x+other.x, this->y+other.y);
}

MultiVal MultiVal::operator-(const MultiVal& other) const {
  return MultiVal(this->x-other.x, this->y-other.y);
}

MultiVal MultiVal::operator*(const MultiVal& other) const {
  return MultiVal(this->x*+other.x, this->y*other.y);
}

MultiVal MultiVal::operator*(const double& a) const {
  return MultiVal(this->x*a, this->y*a);
}


double MultiVal::get_x() {
  return x;
}

double MultiVal::get_y() {
  return y;
}


void MultiVal::randomize() {
  x = rand();
  y = rand();
}
