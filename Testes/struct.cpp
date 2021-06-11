#include<iostream>
using namespace std;

const float pi=3.1415;

typedef struct rectangle{
    float length;
    float height;
};

float area_rec(rectangle r){
    return r.length * r.height;
}

int main(){
    rectangle r1;
    r1.height=5.0,r1.length=10.0;
    cout<<area_rec(r1)<<endl;
    return 0;
}