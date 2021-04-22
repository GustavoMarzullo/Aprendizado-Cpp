#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double contagem =0;

int main(){
    double input =0;
    printf("SOMADOR DE NÚMEOS\n");
    printf("Entre com seus números:\n");
    while(cin>>input){
        contagem+=input;
        cout<<"Total = "<<contagem<<endl;
    }
    return 0;
}