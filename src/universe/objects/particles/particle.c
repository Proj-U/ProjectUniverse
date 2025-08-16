#include<stdlib.h>
#include<stdio.h>
#include"particle.h"
particle new_particle(double px,double py,double pz,double m,double charge){
particle p={px,py,pz,m,0.0,0.0,0.0,charge};
return p;
}
void apply_force(double fx,double fy,double fz,double dt,particle*p){
p->vx+=fx/p->mass*dt;
p->vy+=fy/p->mass*dt;
p->vz+=fz/p->mass*dt;
}
void accelerate_p(double ax,double ay,double az,double dt,particle*p){
p->vx+=ax*dt;
p->vy+=ay*dt;
p->vz+=az*dt;
}
void update_pos_p(double dt,particle*p){
p->x+=p->vx*dt;
p->y+=p->vy*dt;
p->z+=p->vz*dt;
}
void printp(particle p){printf("Particle properties:{\n\tmass=%g\n\tx=%g\n\ty=%g\n\tz=%g\n\tvx=%g\n\tvy%g\n\tvz=%g\n\tcharge=%g\n}\n",p.mass,p.x,p.y,p.z,p.vx,p.vy,p.vz,p.charge);}
