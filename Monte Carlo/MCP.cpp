#include <iostream>
#include <random>
#include <vector>
#include <math.h>

using std::string; 
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::max;
using std::min;


using namespace std;

double randnum (double aa, double bb) { //defining a function to create random numbers
    static std::random_device rd; // non-deterministic, but may be slow
    static std::mt19937 engine{ rd() };
    std::uniform_real_distribution<double> distribution (aa,bb);
    return distribution(engine);
}

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
    double xmin=v[0][0], xmax=0, ymin=v[0][1],ymax=0;
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

double montecarlo(vector<vector<double>>polygon,unsigned n){
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


int main(){
    vector<vector<double>> t={{2,2},{11,2},{9,7},{4,10},{4,7},{1,5}}; //A=48
    double area=montecarlo(t,10000);
    printf("\n");
    cout<<"Area = "<<area<<endl;
    printf("\n");
    return 0;
}

