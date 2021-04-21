#include <pybind11/pybind11.h>
#include <cstdlib>
#include <math.h> 

namespace py = pybind11;

double integral(double a, double b)
{
    if(a>b)
        throw std::domain_error("Tá maluco cacete");

    double soma=0, dx=0.000001;
    while (a<=b)
    {
        soma+=a*a;
        a+=dx;
    }
    return soma*dx;
}

double logaritimo(double x)
{
    double inf=0, erro=0.0001;
    double sup=0.1598*x;
    int num_int=0;
    double y=(inf+sup)/2;
    if (x>=1){
        while(abs(pow(10,y)-x) >= erro){
            ++num_int;
            if(pow(10,y)>x){
                sup=y;
            }
            else{
                inf=y;
            }
        y=(inf+sup)/2;
        }
        return y;
    }
    else if (x>0 and x<1){
        x=1/x;
        sup=0.1598*x;
        y=(inf+sup)/2;
        while(abs(pow(10,y)-x) >= erro){
            ++num_int;
            if(pow(10,y)>x){
                sup=y;
            }
            else{
                inf=y;
            }
        y=(inf+sup)/2;
        }
        y=-y;
        x=1/x;  
        return y;   
    }
    else if (x<0){
        throw std::domain_error("Não existe log de número negativo");
    }
    else{
        throw std::domain_error("Não existe log de zero");
    }
}

PYBIND11_MODULE(log_int, m) {
    m.doc() = "Meu primeiro teste da integração C++ e Python"; // optional module docstring

    m.def("logaritimo", &logaritimo, "Logaritimo decimal", py::arg("x"));

    m.def("integral",&integral, "Integral da função f(x)=x^2",py::arg("a"),py::arg("b")); 
}


//c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` Primeiro_teste.cpp -o log_int`python3-config --extension-suffix`
