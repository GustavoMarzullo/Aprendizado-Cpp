#include <iostream>
#include <pybind11/pybind11.h>
#include <stdio.h> 
#include <math.h> 

namespace py = pybind11;

double fat(double n){ // retorna n!

    if(n==0){
        return 1;
    }
    else if(n==1){
        return n;
    }
    else{
        return n*fat(n-1);
    }
}

double seno(double x_g, double err){
    double seno=0;
    unsigned i=0;
    double termo=err+(double)1;
    double x_rad=x_g*(double)0.0174533;
    while(abs(termo)>=err){
        termo=((pow(-1,i))*pow(x_rad,2*i+1))/fat(2*i+1);
        seno+=termo;
        ++i;
    }
    return seno;
}

double cosseno(double x_g, double err){
    double cosseno=pow(1-pow(seno(x_g,err),2),0.5);
    return cosseno;
}


PYBIND11_MODULE(seno, m) {
    m.doc() = "Seno/Cosseno Taylor"; // optional module docstring
    m.def("seno",&seno, "seno",py::arg("x_g"),py::arg("err")=0.0001);
    m.def("cosseno",&cosseno, "cosseno",py::arg("x_g"),py::arg("err")=0.0001);
}

//c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` seno.cpp -o seno`python3-config --extension-suffix`
