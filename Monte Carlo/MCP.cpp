#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::string; 
using std::cout;
using std::cin;
using std::endl;
using std::vector;


double randnum (double a, double b) { //defining a function to create random numbers
    static std::random_device rd; // non-deterministic, but may be slow
    static std::mt19937 engine{ rd() };
    std::uniform_real_distribution<double> distribution (a,b);
    return distribution(engine);
}

bool even_or_odd(unsigned x){ //return true if x is odd
    if(x%2==0){
        return false;
    }
    else{
        return true;
    }
}

double yc(double x1,double y1,double x2,double y2,double xa){
    return y1+((y2-y1)/(x2-x1))*(xa-x1);
}

string local(double xa,double ya,double x1,double y1,double x2,double y2){//returns the point (xa,ya) location in relation with the line (x1,y1)->(x2,y2)
    if(x1<xa && x2<ya){
        return "Left";
    }
    else if(x1>xa && x2>xa){
        return "Right";
    }
    else if(y1<ya && y2<ya){
        return "Below";
    }
    else if(y1>ya && y2>ya){
        return "Above";
    }
    else{
        return "Between";
    }
}

bool test(double x, double y, vector< vector<double> > v){ //returns true if the point (x,y) is inside the vertices defined by the vector v

    unsigned crossings = 0;
    string above ="Above", between= "Between";

    for(int i=0;i!=v.size()-1;++i){
        double x1= v[i][0], y1=v[i][1];
        double x2= v[i+1][0], y2= v[i+1][1];
        if (local(x,y,x1,y1,x2,y2) == above){
            ++crossings;
        }
        else if (local(x,y,x1,y1,x2,y2) == between){
            if(yc(x1,y1,x2,y2,x)>=y){
                ++crossings;
            }
        }
        else{
            continue;
        }
    }

    if(even_or_odd(crossings)){
        return true;
    }
    else{
        return false;
    }
}

vector<double> limits(vector< vector<double>> v){ //returns de xmin, xmax, ymin and ymax of the polygon
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

double montecarlo(vector< vector<double>> v,unsigned n){

    //organizing my polygon
    vector<double> first = v[0];
    v.push_back(first);

    //getting the limits
    vector<double> Limits= limits(v);
    double xmin=Limits[0],xmax=Limits[1],ymin=Limits[2],ymax=Limits[3];

    //doing the real monte carlo
    unsigned inside=0;
    for(unsigned needles=0; needles!=n;++needles){
        double x=randnum(xmin,xmax);
        double y=randnum(ymin,ymax);
        if(test(x,y,v)){
            ++inside;
        }
    }

    //calculating the area
    double area=((xmax-xmin)*(ymax-ymin))*inside/n;
    return area;
}


int main(){
    vector<vector<double>> t={{0,0},{0.5,1},{1,0}};
    double area=montecarlo(t,(int)1e4);
    cout<<"Area = "<<area<<endl;
    printf("\n");
    return 0;
}