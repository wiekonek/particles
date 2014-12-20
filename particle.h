#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
public:
Particle();
Particle(const Particle& other);
~Particle();
Particle& operator=(const Particle& other);
bool operator==(const Particle& other) const;
};

#endif // PARTICLE_H
