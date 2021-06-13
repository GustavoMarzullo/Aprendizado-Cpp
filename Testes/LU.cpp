#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

typedef vector<vector<double>> matrix;

matrix CreateZeros(int m, int n){
    vector<vector<double>> vec(m, vector<double> (n, 0));
    return vec;
}

void ConvertToLower(matrix &U){
    int i,j;
    int m,n;
    m=U.size();
    n=U[0].size();
    for(i=0;i!=m;++i){
        for(j=0;j!=n;++j){
            if(i<j){
                U[i][j]=0;
            }
            if(i==j){
                U[i][j]=1;
            }
        }
    }
}   

void LU_Decomposition(matrix &A, matrix &L, matrix &U){
    /*
    A is the matrix to be decomposed
    L is the matrix to accept the lower output
    U is the matrix to accept the upper output 
    */
   
   int i,j,k;
   int n=A.size();

   for(k=0;k!=n;++k){
       U[k][k]=A[k][k];

       for(i=k+1;i!=n;++i){
           L[i][k]=A[i][k]/A[k][k];
           U[k][i]=A[k][i];
       }

       for(i=k+1;i!=n;++i){
           for(j=k+1;j!=n;++j){
               A[i][j]-=L[i][k]*U[k][j];
           }
       }
   }
}

void print(const matrix &A){
    int i,j;
    int m,n;
    m=A.size();
    n=A[0].size();
    for(i=0;i!=m;++i){
        for(j=0;j!=n;++j){
            cout<<A[i][j]<<" ";
        }
        cout << endl; //new line 
    }
    printf("\n");
}

matrix CreateSquareIdentity(int n){
    matrix I = CreateZeros(n,n);
    int i,j;
    for(i=0;i!=n;++i){
        for(j=0;j!=n;++j){
            if(i==j){
                I[i][j]=1;
            }
        }
    }
    return I;
}


void Test_LU_Decompostion(){
    //creating the matrix
    matrix A={{2,3,1,5},{6,13,5,19},{2,19,10,23},{4,10,11,31}};
    int m=A.size(), n=A[0].size();
    printf("Original Matrix:\n");
    print(A);

    //initializing L and U
    matrix L=CreateZeros(m,n), U=CreateZeros(m,n);
    ConvertToLower(L);
    
    //performing the LU Decompostion
    LU_Decomposition(A,L,U);

    //printing
    printf("\nThe Lower:\n");
    print(L);
    printf("\nThe Upper:\n");
    print(U);
    printf("\nModified A matrix\n");
    print(A);
}

void concat(matrix& U, vector<double>b){//concats U and b to make the augmented matrix
    int n=U.size();
    for(int i=0;i!=n;++i){
        U[i].push_back(b[i]);
    }
}

vector<double> BackSubstitution(matrix& A){
    int i,j,sum;
    int n=A.size();
    vector<double> result(n,0);

    result[n-1]=A[n-1][n]/A[n-1][n-1];
    for(i=n-2;i>=0;--i){
        sum=0;
        for(j=i+1;j<n;j++){
            sum+=A[i][j]*result[j];
        }
        result[i]=(A[i][n]-sum)/A[i][i];
    }
    return result; 
}

int main(){
    Test_LU_Decompostion();
    return 0;
}
