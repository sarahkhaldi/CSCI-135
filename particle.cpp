/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 9F

The program should declare a new class Particle, which stores position and velocity of the particle.
It models accelerated motion of a particle, which is done by making the velocity of the particle increase on each time step.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D
{
public: 
 double x;
 double y;
 double z;
};

class Particle // stores position and velocity of the particle
{
 public:
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
};


// dynamically allocate memory for a particle and initialize it
Particle *createParticle(double x, double y, double z, double vx, double vy, double vz)
{
 Particle *initialParticle = new Particle;
 initialParticle->x = x;
 initialParticle->y = y;
 initialParticle->z = z;
 initialParticle->vx = vx;
 initialParticle->vy = vy;
 initialParticle->vz = vz;
 return initialParticle;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz)
{
 p->vx = vx;
 p->vy = vy;
 p->vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p)
{
 Coord3D finalParticle = {p->x, p->y, p->z};
 return finalParticle;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt)
{
 p->x = p->x + p->vx * dt;
 p->y = p->y + p->vy * dt;
 p->z = p->z + p->vz * dt;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p)
{
 delete p;
 p = nullptr; // to avoid dangling pointer
}

int main()
{ 
 // make new particle
 Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
 double time = 0.0;
 double dt = 0.1;
 while (time < 3.0)
 {
  // update its velocity
  setVelocity(p, 10.0 * time, 0.3, 0.1);

  // move the particle
  move(p, dt);
  time += dt;

  // reporting its coordinates
  cout << "Time: " << time << " \t";
  cout << "Position: "
       << getPosition(p).x << ", "
       << getPosition(p).y << ", "
       << getPosition(p).z << endl;
 }
 // remove the particle, deallocating its memory
 deleteParticle(p);

 return 0;
}