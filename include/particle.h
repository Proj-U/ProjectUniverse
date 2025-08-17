#ifndef PARTICLE_H
#define PARTICLE_H
#include"constants.h"
typedef struct {double x,y,z,mass,vx,vy,vz,charge;} particle;
particle new_particle(double px,double py,double pz,double m,double charge);
void apply_force(double fx,double fy,double fz,double dt,particle*p);
void update_pos_p(double dt,particle*p);
void accelerate_p(double ax,double ay,double az,double dt,particle*p);
void printp(particle p);
#define electron(x,y,z) (new_particle(x,y,z,m_e,-e))
#define proton(x,y,z) (new_particle(x,y,z,m_p,e))
#define neutron(x,y,z) (new_particle(x,y,z,m_n,e))
#define NULLP (new_particle(-1,-1,-1,-1,-1))
#endif
