#include <iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string frase;

int main(){
    printf("Entre com a sua frase\n");
    getline(cin,frase);
    for(char &i:frase){
        if(ispunct(i)){
            i=' ';
        }
    }
    cout<<frase<<endl;
    return 0;
}