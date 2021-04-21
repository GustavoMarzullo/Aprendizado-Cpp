#include <iostream>

int main()
{
    std::cout << "Código para fazer a soma de todos os números entre dois inteiros. Entre com dois números." << std::endl;
    int x=0,y=0,soma=0; //definindo as variáveis
    std::cin >> x >> y; //entrando com elas
    int x2=x;           // fazendo uma cópia do x
    while (x<=y)
    {
        soma+=x;
        ++x;
    }
    std::cout <<"A soma de todos os números inteiros entre "<< x2 << " e " << y << " é  igual a " << soma << "." << std::endl;
    return 0;
}