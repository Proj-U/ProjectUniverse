#include<stdlib.h>
#include<stdio.h>
#include"wave.h"
#include"direction.h"
wave new_wave(double amplitude,double frequency,double wavelength,double phase,double intensity,double polarization[3],direction dir){
wave w={amplitude,frequency,wavelength,phase,intensity,{polarization[0],polarization[1],polarization[2]},{dir,frequency*wavelength}};
return w;
}
void printw(wave w){
printf("Wave properties:{\n\tamplitude=%f\n\tfrequency=%f\n\twavelength=%f\n\tphase=%f\n\tintensity=%f\n\t",w.amplitude,w.frequency,w.wavelength,w.phase,w.intensity);
for(int n=0;n<3;n++)printf("polarization[%d]=%f\n\t",n,w.polarization[n]);
printf("Velocity={\n\t\tDirection={\n\t\t\tx=%f\n\t\t\ty=%f\n\t\t\tz=%f\n\t\t}\n\t\tspeed=%f\n\t}\n}",w.velocity.direction.x,w.velocity.direction.y,w.velocity.direction.z,w.velocity.speed);
}
