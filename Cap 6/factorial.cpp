#include <iostream>

typedef unsigned long long int llint;

llint factorial(unsigned n){
    llint ret=1, val=n;
    while(val>1){
        ret*=val--;
    }
    return ret;
}

int main(){
    llint n;
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>n;
    std::cout<<factorial(n)<<std::endl;
    return 0;
}

