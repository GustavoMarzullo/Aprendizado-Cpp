#include <iostream>

int main()
{
    int sum=0, val=50;
    while (val <=100)
    {
        sum+=val;
        ++val;
    }
    std::cout <<"A soma de todos os número de 50 a 100 é " << sum << std::endl;
    return 0;
}