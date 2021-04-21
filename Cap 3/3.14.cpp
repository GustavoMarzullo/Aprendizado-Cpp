#include <iostream>
#include<vector>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> v1; // ivec holds objects of type int
int input;



int main(){
    cout<<"Para parar digite qualquer letra"<<endl;
	cout<<"Entre com os números:"<<endl;
    while(cin>>input){
        v1.push_back(input);
    }
    cout<<"O tamanho do vetor é "<<v1.size()<<endl;
    return 0;
}

