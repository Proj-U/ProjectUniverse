#include<stdio.h>
double velocity(double ds,double dt){return ds/dt;}
double tangential_speed(double omega,double r){return omega*r;}
double acceleration(double dv,double dt){return dv/dt;}
double weight(double m,double g){return m/g;}
double dry_friction(double mu,double N){return mu*N;}
double centripetal_acceleration(double v,double r){return (v*v)/r;}
double momentum(double m,double v){return m*v;}
double impulse(double Fm,double dtp){return Fm*dtp;}
double work(double F,double ds){return F*ds;}
double kinetic_energy(double p,double m){return (p*p)/2*m;}
double general_potential_energy(double F,double ds){return -(F*ds);}
double gravitational_potential_energy(double m,double g,double dh){return m*g*dh;}
double efficiency(double W_out,double E_in){return W_out/E_in;}
double power(double dW,double dt){return dW/dt;}
double power_velocity(double F,double v){return F*v;}
double angular_velocity(double dtheta,double dt){return dtheta/dt;}
double angular_acceleration(double domega,double dt){return domega/dt;}
double torque(double r,double F){return r*F;}
