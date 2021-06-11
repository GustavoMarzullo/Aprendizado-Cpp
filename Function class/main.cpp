#include <iostream>
#include <math.h>
#include "class_function.hpp"

using std::cin; using std::cout; using std::endl;

double F(double x){
    return x*x-1;
}


int main(){

    function f(F);
    double val=f.eval(5.38);
    cout<<"f(5) = "<<val<<endl;

    double root = f.root(-5,5);
    cout<<"Root of f = "<<root<<endl;

    double df=f.diff(5);
    cout<<"f'(5) = "<<df<<endl;

    double integral=f.simp(2,3);
    cout<<"Integral of f from 2 to 3 = "<<integral<<endl;

    return 0;
}


