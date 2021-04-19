#include <iostream>
#include <stdio.h> 
#include <math.h> 

double fat(double n){ // retorna n!

    if (n<0){
        throw std::invalid_argument("Valor negativo\n");
    }
    else if(n==0){
        return 1;
    }
    else if(n==1){
        return n;
    }
    else{
        return n*fat(n-1);
    }
}

int main(){
    double x_g; 
    double seno=0, err=0.0001;
    unsigned i=0;
    double termo=err+(double)1;
    printf("Entre com o valor de x: ");
    scanf("%lf", &x_g);
    double x_rad=x_g*0.0174533;
    while(abs(termo)>=err){
        termo=((pow(-1,i))*pow(x_rad,2*i+1))/fat(2*i+1);
        seno+=termo;
        ++i;
    }
    printf("Sen(%f) = %f\n",x_g, seno);
    printf("Num. iterações = %d\n",i);
    return 0;
}
