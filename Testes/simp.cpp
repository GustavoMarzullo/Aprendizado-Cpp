#include <iostream>
#include <math.h>

double f(double x){ //function to be integrated
    return pow(std::sin(x)+1,0.5)*std::cos(x);
}

double simp(double(*function)(double),double a, double b, unsigned n){

    //returning zero if a==b
    if(a==b){
        return 0;
    }
    
    //roundabout to get a negative value if a>b 
    bool a_greater_than_b=false;
    if(a>b){
        a_greater_than_b=true;
        double A=a, B=b;
        a=B;b=A;
    }

    //asserting n is even
    if(n%2!=0){
        ++n;
    }

    //starting to do the real integration
    double dx=(b-a)/(double)n;
    double sum_I=function(a)+f(b);
    double sum_II=0; //sum of the odd terms
    
    for(double i=a+dx; i<b;i+=2*dx){
        sum_II+=function(i);
    }
    
    double sum_III=0;
    for(double i=a+2*dx;i<b;i+=2*dx){
        sum_III+=function(i);
    }

    double integral=(sum_I+4*sum_II+2*sum_III)*(dx/3);
    
    if(a_greater_than_b){
        integral=-integral;
    }

    return integral;
}

int main(){
    double pi=3.1415926536;
    printf("\n");
    printf("The integral of f(x)=sqrt(sin(x)+1)*cos(x) from pi to 3*pi/2\n");
    printf("If my code is right it should return -2/3\n\n");
    double I=simp(f,pi,3*pi/2,500);
    printf("Integral = %.10lf\n\n",I);
    return 0;
}
