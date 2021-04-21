#include <iostream>

int soma(int x, int y){
    return x+y;
}

int dif(int x, int y){
    return x-y;
}

int op(int x, int y, int(*function)(int, int)){
    return function(x,y);
}

int main(void){
    int S=op(5,3,soma);
    int D=op(5,3,dif);
    printf("Soma = %i\n",S);
    printf("Diferença = %i\n",D);
    return 0;
}