#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class person{
private://class attributes
    string name;
    int age;
    float height;
    float weight;

public://class methods
    void setter(string Name, int Age, float Height, float Weight){
        name=Name;
        age=Age;
        height=Height;
        weight=Weight;
    }

    float imc(){
        return weight/(height*height);
    }

    void imc_level(){
        float nivel=imc();
        if(nivel<18.5) printf("Abaixo do peso\n");
        else if(nivel>=18.5 and nivel<25) printf("Peso ideal\n");
        else if (nivel >=25 and nivel <30) printf("Levemente acima do peso\n");
        else if (nivel >=30 and nivel<35) printf("Obesidade grau I\n");
        else if(nivel>=35 and nivel<40) printf("Obesidade grau II (severa)\n");
        else printf("Obesidade grau III (mórbida)\n");
    }

    void print(){
        cout<<"Nome: "<<name<<endl;
        cout<<"Idade: "<<age<<endl;
        printf("Altura: %.2fm\n",height);
        printf("Peso: %.0fkg\n",weight);
        printf("IMC: %.1f\n",imc());
        imc_level();
        printf("-----------------\n");
    }
};

int main(){
    person Ana;
    person Gustavo;
    person Ricardo;
    person Eduardo;
    Ana.setter("Ana",50,1.65,68);
    Gustavo.setter("Gustavo",21,1.82,79);
    Ricardo.setter("Ricardo",57,1.76,80.3);
    Eduardo.setter("Eduardo",18,1.75,93);
    Gustavo.print();
    Eduardo.print();
    Ana.print();
    Ricardo.print();
    return 0;
}