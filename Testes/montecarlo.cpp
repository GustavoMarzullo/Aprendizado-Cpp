#include <stdio.h>
#include <random> //https://www.cplusplus.com/reference/random/

//https://stackoverflow.com/questions/46748109/uniform-random-numbers-are-the-same-in-all-runs
double randnum (double aa, double bb) { //defining a function to create random numbers
    static std::random_device rd; // non-deterministic, but may be slow
    static std::mt19937 engine{ rd() };
    std::uniform_real_distribution<double> distribution (aa,bb);
    return distribution(engine);
}

int main(){
    unsigned i;
    unsigned dentro_circ =0;
    printf("Método de Monte Carlo para achar o valor de pi.\n");
    printf("Quantas iterações deseja fazer?\n");
    scanf("%i",&i);
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1.0,1.0);
    for (unsigned j=0; j<i; ++j){
        double x=randnum(-1.0,1.0);
        double y=randnum(-1.0,1.0);
        if(x*x+y*y<=1){
            ++dentro_circ;
        }
    }
    double pi=4*dentro_circ/(double)i; //https://stackoverflow.com/questions/7571326/why-does-dividing-two-int-not-yield-the-right-value-when-assigned-to-double
    printf("%.10lf \n",pi);
    //system("pause");  
    return 0;
}
