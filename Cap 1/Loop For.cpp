#include <iostream>

int main()
{
    int sum=0;
    for (int val=1; val<=10; val++)
    {
       sum+=val;
    }
    std::cout << "A soma dos inteiros de 1 a 10 é " << sum << "." <<std::endl;
    return 0;
}