#include"maths.h"
#include<math.h>
static unsigned long long rng_state = 88172645463325252ULL;
double ran(){
unsigned long long x = rng_state;
x^=x<<13;
x^=x>>7;
x^=x<<17;
rng_state=x;
return(x&0xFFFFFFFFFFFFULL)/(double)0x1000000000000ULL;
}
double powerof(double x,double y){
double z=x;
for(int n=0;n<y;n++)x*=z;
if(y<0)x=1/x;
if(y==0)x=1;
if(y==1)x=z;
return x;
}
double sine(double x){
const int TERMS=10;
double term=x;
double sum=term;
for(int n=1;n<TERMS;n++){
term*=-1*x*x/((2*n)*(2*n+1));
sum+=term;
}
return sum;
}
double cosine(double x){
const int TERMS=10;
double term=1;
double sum=term;
for(int n=1;n<TERMS;n++){
term*=-1*x*x/((2*n-1)*(2*n));
sum+=term;
}
return sum;
}
double absolute(double x){return x<0?-x:x;}
double acosine(double x){
double negate = x<0?1:0;
x = absolute(x);
double ret = -0.0187293;
ret = ret * x;
ret = ret + 0.0742610;
ret = ret * x;
ret = ret - 0.2121144;
ret = ret * x;
ret = ret + 1.5707288;
ret = ret * sqrt(1.0-x);
return negate ? 3.141592653589793 - ret : ret;
}
