#include <stdio.h>

typedef struct{
    float length;
    float height;
}rectangle;


void change(rectangle* r, float new_l, float new_h){
    (*r).length= new_l;
    (*r).height= new_h;
}

int main(){
    rectangle r1;
    r1.length=10.0;
    r1.height=5.0;

    float new_lenght, new_height;
    printf("Enter the rectangle's new length and height: ");
    scanf("%f %f",&new_lenght,&new_height);

    change(&r1,new_lenght,new_height);

    printf("Length = %.2f Height = %.2f\n",r1.length,r1.height);
    return 0;
}

