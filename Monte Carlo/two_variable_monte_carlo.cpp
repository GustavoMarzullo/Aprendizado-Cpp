#include <iostream>
#include <random>
#include <vector>
#include <math.h> 

using std::string; 
using std::cout;
using std::cin;
using std::endl;
using std::vector;

double randnum (double a, double b) { //defining a function to create random numbers
    static std::random_device rd; 
    static std::mt19937 engine{ rd() };
    std::uniform_real_distribution<double> distribution (a,b);
    return distribution(engine);
}


//functions do check if the point is inside or outside of the polygon

double yc(double x1,double y1,double x2,double y2,double xa){
    return y1+((y2-y1)/(x2-x1))*(xa-x1);
}

unsigned local(double xa,double ya,double x1,double y1,double x2,double y2){//returns the point (xa,ya) location in relation with the line (x1,y1)->(x2,y2)
    if(x1<xa && x2<xa){
        return 0; //left
    }
    else if(x1>xa && x2>xa){
        return 1; //right
    }
    else if(y1<ya && y2<ya){
        return 2; //below
    }
    else if(y1>ya && y2>ya){
        return 3; //above
    }
    else{
        return 4; //between
    }
}

bool test(double x, double y, vector< vector<double> > v){ //returns true if the point (x,y) is inside the vertices defined by the vector v
    unsigned crossings = 0;

    for(unsigned i=0;i!=v.size()-1;++i){
        double x1=v[i][0],y1=v[i][1];
        double x2=v[i+1][0],y2=v[i+1][1];
        unsigned loc=local(x,y,x1,y1,x2,y2);
        if(loc==3){
            ++crossings;
        }
        else if(loc==4){
            if(yc(x1,y1,x2,y2,x)>=y){
                ++crossings;
            }
        }
        else{
            continue;
        }
    }
    
    return (crossings%2!=0);
}

vector<double> limits(vector< vector<double>> v){ //returns the xmin, xmax, ymin and ymax of the polygon
    double xmin=v[0][0], xmax=v[0][0], ymin=v[0][1],ymax=v[0][1];
    for(vector<double> i : v){
        if(i[0]<xmin){
            xmin=i[0];
        }
        if(i[0]>xmax){
            xmax=i[0];
        }
        if(i[1]<ymin){
            ymin=i[1];
        }
        if(i[1]>ymax){
            ymax=i[1];
        }
    }
    vector<double> vec={xmin,xmax,ymin,ymax};
    return vec;
}

//the real monte carlo

vector<double> integral(double (*f)(double,double),vector<vector<double>> boundaries,unsigned n=10000){
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
    return 16-x*x-2*y*y;
}

int main(){
    vector<vector<double>> boundaries = {{0,0},{2,0},{2,2},{0,2}};
    vector<double>V = integral(f,boundaries,100000); //should be 48 
    printf("\nArea = %lf +/- %lf\n",V[0],V[1]);
    return 0;
}

/*
OUTPUT:
Area = 47.992003 +/- 0.033731
*/

