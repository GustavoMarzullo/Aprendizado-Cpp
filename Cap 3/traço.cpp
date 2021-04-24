#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int m=4;
    int n=4;
    int A[m][n]={
                {1,2,3,5},
                {4,5,6,-1},
                {7,8,9,0-8},
                {0,0,0,-5}};
    int count =0;

    for(int i=0;i!=m;++i){
        for(int j=0;j!=n;++j){
            if(i==j){
                count+=A[i][j];
            }
        }
    }
    cout<<"Tr(A) = "<<count<<endl;
    return 0;
}
