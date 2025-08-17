#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "energy.h"
#include"singularity.h"
#include"particle.h"
#include"maths.h"
singularity new_sing(unsigned long long nop,double mass,double density){
singularity s={};
particle ps[nop];
double mpp=mass/nop;
double mr=cbrt((3*mass)/(4*PI*density));
for(unsigned long long n=0;n<nop;n++){
double r=cbrt(ran())*mr;
double theta=ran()*2*PI;
double phi=acos(2*ran()-1);
double x=r*sin(phi)*cos(theta);
double y=r*sin(phi)*sin(theta);
double z=r*cos(phi);
ps[n]=new_particle(x,y,z,mpp,0);
printf("Created particle:\n");
printp(ps[n]);
s.particles[n]=ps[n];
}
s.density=density;
s.nop=nop;
return s;
}
