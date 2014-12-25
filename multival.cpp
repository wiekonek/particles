#include "multival.h"

MultiVal::MultiVal(): x(0), y(0) {}

MultiVal::MultiVal(double x, double y): x(x), y(y) {}

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
