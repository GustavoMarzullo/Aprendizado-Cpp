#include <iostream>

class vector{
    friend std::ostream &print_vector(std::ostream &os, const vector& item);

    private: 
    int x,y;

    public:
    vector () {}; //default constructor 

    vector (int a,int b) {x=a;y=b;}; //class constructor
    
    vector operator+(const vector& other){
        vector temp;
        temp.x=x+other.x;
        temp.y=y+other.y;
        return temp;
    }

    vector operator-(const vector& other){
        vector temp;
        temp.x=x-other.x;
        temp.y=y-other.y;
        return temp;
    }
};

std::ostream &print_vector(std::ostream &os, const vector& item){ //print function
    os<<"("<<item.x<<","<<item.y<<")";
    return os;
}

int main(){
    vector a(1,2);
    vector b(5,6);
    vector c;
    c=a+b;
    print_vector(std::cout,c);
    printf("\n");
    return 0;
}

