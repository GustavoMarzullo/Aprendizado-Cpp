#include <iostream>
#include <string>
#include <math.h>

struct pessoa{
    unsigned idade;
    double peso;
    double altura;
};

int main(){
    pessoa gustavo;
    gustavo.idade=21;
    gustavo.peso=81;
    gustavo.altura=1.82;
    double imc=gustavo.peso/(gustavo.altura*gustavo.altura);
    printf("Idade: %i anos\nPeso: %.1lf Kg\nAltura: %.2lf m\nIMC=%.1lf\n\n",gustavo.idade, gustavo.peso, gustavo.altura,imc);
    return 0;
}