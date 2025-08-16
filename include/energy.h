#ifndef ENERGY_H
#define ENERGY_H
#include"particle.h"
#include"wave.h"
typedef enum {
    KINETIC,
    POTENTIAL,
    ELECTRIC,
    MAGNETIC,
    RADIATION,
    THERMAL,
    NUCLEAR
} energy_type;
typedef struct{
double value,decay_rate,cap,ts,direction[3];
int is_active;
energy_type type;
union{
wave*w;
particle*p;
}src;
}energy;
energy p_energy(double val,double dr,double cap,double ts,double dir[3],int active,energy_type type,particle*p);
energy w_energy(double val,double dr,double cap,double ts,double dir[3],int active,energy_type type,wave*w);
void printe(energy en);
#endif
