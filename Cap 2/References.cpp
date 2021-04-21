#include <iostream>

int main(){
    
    int ival=1024;
    int &refVal=ival;
    printf("%i\n%i\n", ival, refVal);
    return 0;
}