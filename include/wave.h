#ifndef WAVE_H
#define WAVE_H
#include "direction.h"
typedef struct{
double amplitude,frequency,wavelength,phase,intensity,polarization[3];
struct{
direction direction;
double speed;
}velocity;
}wave;
wave new_wave(double amplitude,double frequency,double wavelength,double phase,double intensity,double polarization[3],direction dir);
void printw(wave w);
#endif
