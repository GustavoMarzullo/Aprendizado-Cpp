#ifndef BISECTION
#define BISECTION

#include <iostream>
#include<math.h>
#include <stdexcept>

using std::cerr;

int signal(double x){
    if(x>0){
        return 1;
        }
    else if (x<0){
        return -1;
        }
    else{
        return 0;
        }
}

double bisec(double (*f)(double),double a,double b, unsigned h=10000000){//returns the root of f in [a,b]. If does not exist returns an error
    
    double epsilon=(b-a)/h;

    double x1=a;
    double f1=f(x1);
    if (f1==0.0){return x1;}

    double x2=b;
    double f2=f(x2);
    if (f2==0.0){return x2;}
    
    double x3,f3;
    while(abs(x2-x1)>=epsilon){
        x3=(x1+x2)/2.0;
        f3=f(x3);
        if(signal(f2)!=signal(f3)){
            x1=x3;
            f1=f3;
        }
        else{
            x2=x3;
            f2=f3;
        }
    }

    return (x1+x2)/2.0;
}
#endif