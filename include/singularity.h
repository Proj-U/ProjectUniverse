#ifndef SINGULARITY_H
#define SINGULARITY_H
#include"particle.h"
typedef struct{
unsigned long long nop;
double density;
particle particles[];
}singularity;
singularity new_sing(unsigned long long nop,double mass,double density);
#endif
