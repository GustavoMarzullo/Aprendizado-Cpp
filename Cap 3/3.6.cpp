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
        if(isgraph(i)){
            i='X'; //"In C and C++ the single quote is used to identify the single character, and double quotes are used for string literals."
        }
    }
    cout<<frase<<endl;
    return 0;
}
