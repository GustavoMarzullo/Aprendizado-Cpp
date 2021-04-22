#include <pybind11/functional.h>
#include <random>

namespace py = pybind11;

double randnum (double aa, double bb) { //defining a function to create random numbers
    static std::random_device rd; // non-deterministic, but may be slow
    static std::mt19937 engine{ rd() };
    std::uniform_real_distribution<double> distribution (aa,bb);
    return distribution(engine);
}

double integral(const std::function<double(double)> &f, double A,  double B,  unsigned n){

    bool b_greater_than_a = true;
    double a=A;
    double b=B;
    if (b<a){
        b=A;
        a=B;
        b_greater_than_a=false;
    }
    double soma=0;
    for(unsigned i=0;i!=n;++i){
        double x=randnum(a,b);
        soma+=f(x);
    }
    double media=(double)soma/n;
    if(!b_greater_than_a){
        media=-media;
    }
    return media*(b-a);
}

PYBIND11_MODULE(int_mc, m) {
    m.doc() = "Integral de Monte Carlo"; // optional module docstring
    m.def("integral",&integral, "integral" ,py::arg("f"),py::arg("a"),py::arg("b"),py::arg("n")=10000); 
}

//c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` int_mc.cpp -o int_mc`python3-config --extension-suffix`
