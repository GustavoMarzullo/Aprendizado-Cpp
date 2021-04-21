#include <iostream>

int main()
{
    int sum=0, val=1;
    //execute o código enquanto val é menor ou igual a 10
    while (val <= 10)
    {
        sum+=val; //sum=sum+val
        ++val; //adiciona 1 a val
    }
    std::cout << "A soma de dos números de 1 até 10 é " << sum << std::endl;
    return 0;
}