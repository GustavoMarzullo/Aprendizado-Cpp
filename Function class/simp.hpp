#ifndef SIMP
#define SIMP

double Simp(double (*function)(double),double a, double b, unsigned n){//simpson's integral

    //returning zero if a==b
    if(a==b){
        return 0;
    }
    
    //roundabout to get a negative value if a>b 
    bool a_greater_than_b=false;
    if(a>b){
        a_greater_than_b=true;
        double A=a, B=b;
        a=B;b=A;
    }

    //asserting n is even
    if(n%2!=0){
        ++n;
    }

    //starting to do the integration
    double dx=(b-a)/(double)n;
    double sum_I=function(a)+function(b);
    double sum_II=0; //sum of the odd terms
    
    for(double i=a+dx; i<b;i+=2*dx){
        sum_II+=function(i);
    }
    
    double sum_III=0;
    for(double i=a+2*dx;i<b;i+=2*dx){
        sum_III+=function(i);
    }

    double integral=(sum_I+4*sum_II+2*sum_III)*(dx/3);
    
    if(a_greater_than_b){
        integral=-integral;
    }

    return integral;
}

#endif