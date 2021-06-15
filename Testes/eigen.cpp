#include <iostream>
#include <Eigen/Dense>

using std::cout;
using std::cin;
using std::endl;
using namespace Eigen;

void first(){
    Matrix <float,3,3> A;
    A.setZero();
    cout<<A<<endl;
}

void second(){
    Matrix <int, 2, 2> A;
    A(0,0)=1;
    A(0,1)=2;
    A(1,0)=3;
    A(1,1)=4;
    cout<<A<<endl;
}

void third(){
    Matrix4d D;
    D<<1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
    cout<<D<<endl;
}

void mult(){
    Matrix2d A,B;
    A<<1,2,3,4;
    B=A.inverse();
    cout<<A*B<<endl;

}

int main(){
    mult();
    return 0;
}