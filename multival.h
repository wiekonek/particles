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
  
  bool operator< (const MultiVal&) const;
  MultiVal operator+ (const MultiVal&) const;
  MultiVal operator- (const MultiVal&) const;
  MultiVal operator* (const MultiVal&) const;
  MultiVal operator* (const double&) const;
  
  double get_x();
  double get_y();
  virtual void randomize();
};

#endif // MULTIVAL_H
