#ifndef CLASS_FUNCTION
#define CLASS_FUNCTION

#include "bisection.hpp"
#include "derivative.hpp"
#include "simp.hpp"

using std::cin; using std::cout; using std::endl;

class function{
private:
    double (*f)(double); //the proper function

public:
    function () {} //default constructor
    function(double (*F)(double)){f=F;}; //constructor

    double eval(double n){
        return f(n);
    }

    double root(double a, double b, unsigned h=10000000){//returns the root of f in [a,b]. If does not exist returns an error
        return bisec(f,a,b);
    }

    double diff(double x,double h=1e-5, double error=1e-5){
        return ridder_diff(f,x,h,error);
    }

    double simp(double a, double b, unsigned n=100){//simpson's integral
        return Simp(f,a,b,n);
    }
};
#endif