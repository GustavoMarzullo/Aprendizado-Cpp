#include <iostream>
/*
Código para calcular a integral da função f(x)=x^2

Meu primeiro programa em C++ :)

You may say ain't free. But it don't worry me
*/
int main()
{
    double soma=0, dx=0.000001, a=0, b=3;
    while (a<=b)
    {
        soma+=a*a;
        a+=dx;
    }
    std::cout <<"A integral de 0 a 3 de f(x)=x^2 é igual a " << soma*dx << std::endl;
    return 0;
}
