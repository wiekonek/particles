#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "position.h"
#include "direction.h"
#include "multival.h"
#include "fstream"

using std::stringstream;
using std::string;
using std::cout;
using std::vector;

namespace world_of_particles {
  class Particle {
  protected:
    string name;
    Position *position;
    Direction *direction;
    MultiVal *max;
    double r, m;
  public:
    Particle( MultiVal*, string, Position*, Direction*, double, double);
    virtual ~Particle();
    
    Position& get_position() { return *position; }
    Direction& get_direction() { return *direction; }
    double get_m() { return m; }
    double get_r() { return r; }
    string get_name() { return name; }
    MultiVal* get_size() {return max; }
    
    virtual void draw( string );
    virtual void draw() = 0;
    virtual void save( string, double );
    virtual void save() = 0;
    virtual void move( vector<Particle*> ) = 0;
    virtual void updateDirection();
    bool collide(Particle*);
    double distanceTo(Particle*);
    void set_r(double);
    void set_m(double);
    
  };
}

#endif // PARTICLE_H
