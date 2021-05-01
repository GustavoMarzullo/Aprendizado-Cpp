#include <iostream>

using namespace std;

int main(){

    //initializing the counters
    unsigned a_count=0,e_count=0,i_count=0,o_count=0,u_count=0;

    char ch;
    while(cin>>ch){
        //if ch is a vowel, increment the appropriate counter
        switch(ch){
            case 'a': ++a_count;break;
            case 'e': ++e_count;break;
            case 'i': ++i_count;break;
            case 'o': ++o_count;break;
            case 'u': ++u_count;break;
        }
    }

    //printing the results
    cout<< "\n\nNumber of a: "<<a_count<<"\n"
        << "Number of e: "<<e_count<<"\n"
        << "Number of i: "<<i_count<<"\n"
        << "Number of o: "<<o_count<<"\n"
        << "Number of u: "<<u_count<<"\n\n" <<endl;
    return 0;
}