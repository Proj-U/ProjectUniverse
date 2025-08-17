#include"maths.h"
#include<math.h>
static unsigned long long rng_state = 88172645463325252ULL;
double random(){
unsigned long long x = rng_state;
x^=x<<13;
x^=x>>7;
x^=x<<17;
rng_state=x;
return(x&0xFFFFFFFFFFFFULL)/(double)0x1000000000000ULL;
}
double integral(double(*f)(double),double a,double b,int n){
double dx=(b-a)/n;
double sum=0;
for(int x=0;x<n;x++)sum+=f(a+x*dx)*dx;
return sum;
}
