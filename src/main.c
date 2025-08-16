#include<stdio.h>
#include"maths.h"
#include"particle.h"
#include"constants.h"
#include"direction.h"
#include"wave.h"
particle*create_universe_singularity(double num){
particle*singularity=malloc(sizeof(particle)*num);
if(!singularity){
perror("Failed to allocate singularity");
return NULL;
}
double universe_mass=1e53;
double mass_per_particle=universe_mass/num;
for(int i=0;i<num;i++){
double r=powerof(ran(),1.0/3.0)*1e-15; 
double theta=ran()*2*PI;
double phi=acosine(2*ran()-1);
double x=r*sine(phi)*cosine(theta);
double y=r*sine(phi)*sine(theta);
double z=r*cosine(phi);
singularity[i]=new_particle(x,y,z,mass_per_particle,0);
printf("Created particle:\n");
printp(singularity[i]);
}
return singularity;
}
int main(){
particle p=electron(1,2,5);
printp(p);
double pol[3]={2,6,2};
direction d={95,5,1};
wave w=new_wave(9,2,5,1,5,pol,d);
printw(w);
particle*sin=create_universe_singularity(100);
for(unsigned long long n=0;n<100;n++) printp(sin[n]);
}
