#ifndef POSITION_H
#define POSITION_H

#include "multival.h"
#include "direction.h"


namespace world_of_particles {
  class Position : public MultiVal {
  public:
    Position() : MultiVal() {}
    Position( double one, double two ) : MultiVal( one, two ) {}
    Position( Position* );
    virtual void update( Direction );
    virtual void randomize( int, int );
  };
}
#endif // POSITION_H
