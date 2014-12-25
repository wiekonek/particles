#ifndef MULTIVAL_H
#define MULTIVAL_H

#include <cstdlib>

class MultiVal {
protected:
  double x;
  double y;

public:
  MultiVal();
  MultiVal(double, double);
  double get_x();
  double get_y();
  virtual void randomize();
};

#endif // MULTIVAL_H
