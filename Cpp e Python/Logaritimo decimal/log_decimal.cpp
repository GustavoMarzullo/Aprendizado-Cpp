#include <pybind11/pybind11.h>

namespace py = pybind11;

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

PYBIND11_MODULE(log10, m) {
    m.doc() = "Blablabla"; // optional module docstring

    m.def("logaritimo", &logaritimo, "Logaritimo decimal", py::arg("x"));
}


//c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` log_decimal.cpp -o log10`python3-config --extension-suffix`
