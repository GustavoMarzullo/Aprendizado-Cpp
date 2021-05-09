#include <iostream>
#include <vector>
#include <cmath>
#include <boost/math/distributions/students_t.hpp>
#include "tools.h"

using std::string; 
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using boost::math::students_t;


double montecarlo(matrix polygon,unsigned n){
    //getting the limits
    vector<double> Limits= limits(polygon);
    double xmin=Limits[0],xmax=Limits[1],ymin=Limits[2],ymax=Limits[3];

    //organizing my polygon
    polygon.push_back(polygon[0]);

    //doing the real monte carlo
    unsigned inside=0;
    for(unsigned needles=0; needles!=n;++needles){
        double x= randnum(xmin,xmax), y=randnum(ymin,ymax);
        if(test(x,y,polygon)){
            ++inside;
        }
    }
    
    //calculating the area
    return (xmax-xmin)*(ymax-ymin)*inside/n;
}


//starting to make a confindence interval of the area

vector<double> mean_and_sd(vector<double>data){
    double sum= 0, mean, sd=0;
    for(unsigned i=0;i!=data.size();++i)
    {
        sum += data[i];
    }
    mean=sum/data.size();

    for(unsigned i=0;i!=data.size();++i)
        sd+=pow(data[i]-mean, 2);

    sd=sqrt(sd/data.size());

    return {mean,sd};
}

double confidence_interval(double sd, double n,double alpha){//Source: https://www.boost.org/doc/libs/1_56_0/libs/math/doc/html/math_toolkit/stat_tut/weg/st_eg/tut_mean_intervals.html

    students_t dist(n-1);
    double T = quantile(complement(dist, alpha/2));
    double w = T * sd / sqrt(double(n));
    return w;
}

vector<double>estimate(const matrix& polygon,unsigned needles, unsigned series,bool verbose){
    vector<double>est;

    for(unsigned i=0;i!=series;++i){
        est.push_back(montecarlo(polygon,needles));
    }

    vector<double>mean_sd = mean_and_sd(est);
    double mean=mean_sd[0],sd=mean_sd[1];
    double w=confidence_interval(sd,series,0.05);

    if(verbose){
        printf("\nArea = %.5lf +/- %.5lf \nNeedles = %i\n____________________________________\n",mean,w,needles);
    }

    return {mean,w};
}

void area(const matrix& polygon,double precision=1,unsigned series=20,unsigned needles=1000,bool verbose=true){
    double uncertain=precision;

    while(uncertain>=precision){
        vector<double> mean_w=estimate(polygon,needles,series,verbose);
        double mean=mean_w[0], w=mean_w[1];
        uncertain=100*(w/mean);
        needles*=2;
    } 
}

int main(){
    unsigned sides;

    printf("\n");
    cout<<"Monte Carlo estimative of a polygon's area"<<endl;
    cout<<"How many side does your polygon have?"<<endl;
    scanf("%i",&sides);

    printf("\n");
    double polygon[sides][2];
    cout<<"Line by line, enter the (x,y) position of each vertex in your polygon (always clockwise or anticlockwise)"<<endl;
    for (unsigned i = 0; i!=sides; i++){
        for (unsigned j = 0; j!=2; j++){
            cin >> polygon[i][j];
        }
    }

    //array to vector
    matrix vec;
    for (unsigned i = 0; i!=sides; i++){
        vector<double> temp;
        for (unsigned j = 0; j!=2; j++){
            temp.push_back(polygon[i][j]);
        }
        vec.push_back(temp);
    }

   printf("\n");
   cout<<"Starting to calculate the area"<<endl;
   area(vec,0.5);
   cout<<"\nFinished\n"<<endl;
   return 0;
}

/*
Or you could try the non-dumb way: https://math.stackexchange.com/questions/492407/area-of-an-irregular-polygon
*/
