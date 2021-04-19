#include <iostream>


int main(){
    int val = 42;
    int *val2 = &val;
    int &val3=val;
    printf("Antes\n");
    printf("val = %i\nval2 = %i\nval3 = %i\n\n",val, *val2,val3);
    val = 50;
    printf("Depois\n");
    printf("val = %i\nval2 = %i\nval3 = %i\n",val, *val2,val3);

    return 0;
}