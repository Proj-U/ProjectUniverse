#ifndef PARTICLE_H
#define PARTICLE_H
#include"constants.h"
#include"vector.h"
typedef struct{
vector3 velocity,pos;
double mass,charge;
}particle;
particle new_particle(double x,double y,double z,double m,double charge);
void printp(particle p);
#define electron(x,y,z) (new_particle(x,y,z,m_e,-e))
#define proton(x,y,z) (new_particle(x,y,z,m_p,e))
#define neutron(x,y,z) (new_particle(x,y,z,m_n,e))
#define NULLP (new_particle(-1,-1,-1,-1,-1))
#endif
