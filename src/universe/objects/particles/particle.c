#include<stdlib.h>
#include<stdio.h>
#include"particle.h"
#include"vector.h"
particle new_particle(double x,double y,double z,double m,double charge){return (particle){{0.0,0.0,0.0},{x,y,z},m,charge};}
void acc_p(particle*p,vector3 a,double dt){
p->velocity.x+=a.x*dt;
p->velocity.y+=a.y*dt;
p->velocity.z+=a.z*dt;
}
void update_ppos(particle*p,double dt){
p->pos.x+=p->velocity.x*dt;
p->pos.y+=p->velocity.y*dt;
p->pos.z+=p->velocity.z*dt;
}
void printp(particle p){printf("Particle properties:{\n\tmass=%g\n\tx=%g\n\ty=%g\n\tz=%g\n\tvx=%g\n\tvy%g\n\tvz=%g\n\tcharge=%g\n}\n",p.mass,p.pos.x,p.pos.y,p.pos.z,p.velocity.x,p.velocity.y,p.velocity.z,p.charge);}
