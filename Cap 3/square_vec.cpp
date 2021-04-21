#include <iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void square (vector <int> &v){ //passando v por referência para mutar ele
    for(unsigned x= 0; x!=v.size();++x){
        v[x]*=v[x];
    }
}


int main(){
    vector<int> vec;
    int input;
    cout<<"Para parar digite qualquer letra"<<endl;
	cout<<"Entre com os números:"<<endl;
    while(cin>>input){
        vec.push_back(input);
    }
    square(vec);
    for(unsigned n: vec){
        printf("%i ",n);
    }
    printf("\n\n");
    return 0;
}