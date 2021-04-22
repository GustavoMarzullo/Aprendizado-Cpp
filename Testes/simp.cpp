#include <iostream>

double f(double x){//function to be integrated
    return x*x;
}

double simp(double(*function)(double),double a, double b, unsigned n){

    //returning zero if a==b
    if(a==b){
        return 0;
    
    }
    //roundabout to get a negative value if b>a 
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

    //starting to do the real integral
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
    printf("Integral of f(x)=x^2 from 0 to 3\n");
    printf("If my code is right it should return 9\n");
    double I=simp(f,0,3,100000);
    printf("Integral = %.5lf\n",I);
    return 0;
}
