#include <iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main(){
    vector<int> v;
    int input;
    
    cout<<"Para parar digite qualquer letra"<<endl;
	cout<<"Entre com os números:"<<endl;
	
    while(cin>>input){
        v.push_back(input);
    }
    
    printf("\n");
    
    int v_size=v.size();
    unsigned stop_criterea= v_size/2; 
    
    for(int i=0;i!=stop_criterea;++i){
        cout<<v[i]+v[v_size-i-1]<<endl;
    }
    
    return 0;
}
