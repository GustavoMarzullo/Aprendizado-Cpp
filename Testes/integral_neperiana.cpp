#include <iostream>

double f(double x){
    return 1/x;
}

double integral(double A, double B, double dx){
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
    printf("%f \n",soma*dx);
    return 0;
}

int main(){
    double a, b;
    printf("Insira o limite inferior:\n");
    scanf("%lf",&a);
    printf("Insira o limite superior:\n");
    scanf("%lf",&b);
    integral(a,b,0.000001);
    return 0;
}
