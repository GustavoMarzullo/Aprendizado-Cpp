#include <iostream>
#include <random>
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

unsigned local(double xa,double ya,double x1,double y1,double x2,double y2){//returns the point (xa,ya) location in relation with the line (x1,y1)->(x2,y2)
    if(x1<xa and x2<ya){
        return 0; //left
    }
    else if(x1>xa and x2>xa){
        return 1; //right
    }
    else if(y1<ya and y2<ya){
        return 2; //below
    }
    else if(y1>ya and y2>ya){
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

    return even_or_odd(crossings);
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

double montecarlo(vector< vector<double>>v,unsigned n){
    //getting the limits
    vector<double> Limits= limits(v);
    double xmin=Limits[0],xmax=Limits[1],ymin=Limits[2],ymax=Limits[3];

    //organizing my polygon
    vector<double> first = v[0];
    v.push_back(first);

    //doing the real monte carlo
    unsigned inside=0;
    for(unsigned needles=0; needles!=n;++needles){
        double x= randnum(xmin,xmax), y=randnum(ymin,ymax);
        if(test(x,y,v)){
            ++inside;
        }
    }
    //calculating the area
    double area=(xmax-xmin)*(ymax-ymin)*inside/n;
    return area;
}


int main(){
    vector<vector<double>> t={{2.48,1.38},{2.68,4.9},{6.09,5.80},{8,2.83},{5.76,0.1}};
    double area=montecarlo(t,10000);
    cout<<"Area = "<<area<<endl;
    printf("\n");
    return 0;
}
