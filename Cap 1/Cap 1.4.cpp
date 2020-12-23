# include <iostream>
//Lembra de usar o ctrl + D para indicar o fim do programa na hora de digitar os números
int main()
{
    int soma=0, valor=0;
    while (std::cin>>valor)
    {
        soma+=valor;
    }
    std::cout <<"A soma é " << soma <<"."<<std::endl;
    return 0;
}