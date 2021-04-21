#include <pybind11/functional.h>
#include <cstdlib>
#include <math.h> 

namespace py = pybind11;

double integral(const std::function<double(double)> &f, double A,  double B,  double dx){
    bool b_greater_than_a = true;
    double a=A;
    double b=B;
    if (b<a){
        b=A;
        a=B;
        b_greater_than_a=false;
    }
    double soma = 0;
    while (a<=b){
        soma+=f(a);
        a+=dx;
    }
    if (b_greater_than_a == false){
        soma=-soma;
    }
    return soma*dx;
}

PYBIND11_MODULE(integral, m) {
    m.doc() = "Integral de Riemann"; // optional module docstring
    m.def("integral",&integral, "integral" ,py::arg("f"),py::arg("a"),py::arg("b"),py::arg("dx")=0.0001); 
}

//const std::function<double(double)> &f (método para adicinar uma função f do python,"functional")

//c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` integral.cpp -o integral`python3-config --extension-suffix`
