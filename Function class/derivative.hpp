#ifndef DERIVATIVE
#define DERIVATIVE

#include <math.h>
#include <algorithm>  

double ridder_diff(double (*f)(double), double x,double h, double err){
/*
Returns the derivative of a function func at a point x by Ridders’ method of polynomial extrapolation. The value h is input as an estimated initial stepsize; it need not be small, but rather should be an increment in x over which func changes substantially. An estimate of the error in the derivative is returned as err.
*/

    int ntab=10; //Sets maximum size of tableau
    double con=1.4,con2=(con*con);  //Stepsize decreased by CON at each iteration
    double safe=2.0;//Return when error is SAFE worse than the best so far
    int i,j;
    double errt,fac,hh,ans;
    double a[ntab][ntab];

    if (h == 0.0) throw("h must be nonzero in dfridr.");

    hh=h;
    a[0][0]=(f(x+hh)-f(x-hh))/(2.0*hh);
    for (i=1;i<ntab;i++){//Successive columns in the Neville tableau will go to smaller stepsizes and higher orders of extrapolation
        hh/=con;
        a[0][i]=(f(x+hh)-f(x-hh))/(2.0*hh);
        fac=con2;
        for (j=1;j<=i;j++){//Compute extrapolations of various orders, requiring no new function evaluations
            a[j][i]=(a[j-1][i]*fac-a[j-1][i-1])/(fac-1.0);
            fac=con2*fac;
            errt=std::max(abs(a[j][i]-a[j-1][i]),abs(a[j][i]-a[j-1][i-1]));
            if (errt <= err){//If error is decreased, save the improved answer.
                err=errt;
                ans=a[j][i];
            }
        }
        if (abs(a[i][i]-a[i-1][i-1]) >= safe*err) break; //If higher order is worse by a signiﬁcant factor SAFE, then quit early
    }
    return ans;
}

#endif
