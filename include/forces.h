#ifndef FORCES_H
#define FORCES_H
#include"particle.h"
#include"wave.h"
#include"energy.h"
void compute_gravity(particle*x,particle*y,double dt);
void apply_wtp(particle*p,wave*w,double t,double dt);
void apply_etp(particle*p,energy*en,double dt);
#endif
