#include <iostream>
#include <vector>
#include <cmath>
#include "tools.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<double> integral(double (*f)(double,double),const matrix& boundaries,unsigned n=10000){
    /*
        f: function to be integrated
        boundaires: polygon defining the region of integration
        n: number of interations

        Source: Numerical Recipes (2007) - pag. 397
    */

   //getting the limits
   vector<double> Limits= limits(boundaries);
   double xmin=Limits[0],xmax=Limits[1],ymin=Limits[2],ymax=Limits[3];
   double V=(xmax-xmin)*(ymax-ymin);

   double bracket_f=0,bracket_f_squared=0,z; //declaring the variables to be used in the loop
   for(unsigned i=0;i!=n;++i){
       double x=randnum(xmin,xmax),y=randnum(ymin,ymax);
       if(test(x,y,boundaries)){
           z=f(x,y);
           bracket_f+=z;
           bracket_f_squared+=z*z;
       }

   }

   //calculating the volume
   double mean=bracket_f/n;
   double volume=V*mean;

   //calculating the error
   double mean_error=bracket_f_squared/n;
   double error = V*sqrt((mean_error-mean*mean)/n);

   //finally returning the values
   return {volume,error};
}

double f(double x, double y){
    return 3*x*cos(y)-x*sin(y);
}


int main(){
    double pi2=M_PI/2;
    matrix boundaries = {{0,0},{0,pi2},{3,pi2},{3,0}};
    vector<double> V = integral(f,boundaries,1000000); //should be 9
    printf("\nArea = %lf +/- %lf\n\n",V[0],V[1]);
    return 0;
}

/*
OUTPUT:
Area = 47.992003 +/- 0.033731
*/

