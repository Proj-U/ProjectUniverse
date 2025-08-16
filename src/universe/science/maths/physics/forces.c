#include<stdio.h>
#include<math.h>
#include"constants.h"
#include"particle.h"
#include"wave.h"
#include"energy.h"
void compute_gravity(particle*x,particle*y,double dt){
double dx=y->x-x->x;
double dy=y->y-x->y;
double dz=y->z-x->z;
double r2=dx*dx+dy*dy+dz*dz;
if(r2==0){
fprintf(stderr,"[ERROR] Distance cannot be 0\n[ERROR] Failed to computer gravity\n");
return;
}
double r=sqrt(r2);
double f=(G*x->mass*y->mass)/r2;
double ax=f*dx/(r*x->x);
double ay=f*dy/(r*x->y);
double az=f*dz/(r*x->z);
accelerate_p(ax,ay,az,dt,x);
ax=f*dx/(r*y->x);
ay=f*dy/(r*y->y);
az=f*dz/(r*y->z);
accelerate_p(ax,ay,az,dt,y);
}
void apply_wtp(particle*p,wave*w,double t,double dt){
double x_proj=p->x*w->velocity.direction.x+p->y*w->velocity.direction.y+p->z*w->velocity.direction.z;
double field=w->amplitude*sin((2*M_PI/w->wavelength)*x_proj-2*M_PI*w->frequency*t + w->phase);
double f=field*p->charge;
apply_force(f*w->polarization[0],f*w->polarization[1],f*w->polarization[2],dt,p);
}
void apply_etp(particle*p,energy*en,double dt){
double f=0.0;
switch(en->type){
case KINETIC:{
double speed=sqrt(p->vx*p->vx+p->vy*p->vy+p->vz*p->vz);
double ux=(speed!=0.0)?p->vx/speed:1.0;
double uy=(speed!=0.0)?p->vy/speed:0.0;
double uz=(speed!=0.0)?p->vy/speed:0.0;
double dv=sqrt(2*en->value/p->mass);
apply_force(dv*ux,dv*uy,dv*uz,dt,p);
break;
}case RADIATION:
case ELECTRIC:
    if(en->src.w){
    f=en->value*p->charge;
    apply_force(f*en->src.w->polarization[0],f*en->src.w->polarization[1],f*en->src.w->polarization[2],dt,p);
    }
    break;
case THERMAL:
    f=(en->value/dt)*(random()-0.5);
    apply_force(f,f,f,dt,p);
    break;
default:
    break;
}
en->value-=en->decay_rate*en->value*dt;
if(en->value<0.0)en->value=0.0;
}
