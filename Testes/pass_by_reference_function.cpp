#include <iostream>

int a=2;

int quadrado(int &n){ //se eu passar o n por referência eu modifico ele
    n*=n;
    return 0;
}

int main(){
    printf("Zero: %i\n",a);
    quadrado(a);
    printf("Um: %i\n",a);
    quadrado(a);
    printf("Dois: %i\n",a);
    quadrado(a);
    printf("Três: %i\n",a);
    return 0;
}