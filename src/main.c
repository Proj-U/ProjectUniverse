#include<stdio.h>
#include<math.h>
#include"maths.h"
#include"particle.h"
#include"constants.h"
#include"direction.h"
#include"wave.h"
#include"singularity.h"
int main(){
particle p=electron(1,2,5);
printp(p);
double pol[3]={2,6,2};
direction d={95,5,1};
wave w=new_wave(9,2,5,1,5,pol,d);
printw(w);
singularity s=new_sing((unsigned long long)1e90,1.67e-27,5e96);
}
