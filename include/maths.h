#ifndef MATHS_H
#define MATHS_H
#define NOE(arr) (sizeof(arr)/sizeof(arr[0]))
double random();
double integral(double(*f)(double),double a,double b,int n);
#endif
