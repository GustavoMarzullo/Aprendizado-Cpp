#include<iostream>
#include<math.h>


double f(double x){
    return pow(x,2)-2*x-3;
}

int sinal(double x){
    if(x>0){
        return 1;
    }
    else if(x<0){
        return -1;
    }
    else{
        return 0;
    }
}

double raiz(double(*function)(double), double a, double b){
    double epsilon=(b-a)/(double)100000;
    double x1=a;
    double f1=function(x1);
    if (f1==0){
        return x1;
    }
    double x2=b;
    double f2=function(x2);
    if(f2==0){
        return x2;
    }
    while(abs(x2-x1)>=epsilon){
        double x3=(x1+x2)/2;
        double f3=function(x3);
        if (sinal(f2)!=sinal(f3)){
            x1=x3;
            f1=f3;
        }
        else{
            x2=x3;
            f2=f3;
        }
    }

    double media = (x1+x2)/2;
    return media;
}

int main(){
    double Raiz=raiz(f,-10,0);
    printf("Raiz = %.3lf\n",Raiz);
    return 0;
}
