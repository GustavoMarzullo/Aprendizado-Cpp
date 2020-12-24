#include <iostream>
#include <cstdlib>
#include <math.h> 

/*
Calculando o logaritimo decimal por biseção

Se quiser saber como cheguei em sup=0.1598*x envie um email para gustavmarzullo@gmail.com

A dreaded sunny day
So let's go where we're happy
And I meet you at the cemetry gates 
*/

int main()
{
    double inf=0, x=0, erro=0.0001;
    std::cout <<"Calculadora de log decimal. Entre com o número: " << std::endl;
    std::cin >> x; 
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
        std::cout <<"O log de " << x << " é " << y << std::endl;
        std::cout << "Nº de iterações: " << num_int << std::endl;
        return 0;
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
        std::cout <<"O log de " << x << " é " << y << std::endl;
        std::cout << "Nº de iterações: " << num_int << std::endl;
        return 0;   
    }
    else if (x<0){
        std::cout<<"Não existe log de número negativo"<<std::endl;
        return 0;
    }
    else{
        std::cout<<"Não existe log de 0" <<std::endl;
        return 0;
    }
}
