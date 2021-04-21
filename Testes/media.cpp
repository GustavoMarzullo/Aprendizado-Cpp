#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	double input;
	double n=0;
	unsigned count=0;
	cout<<"Para parar digite qualquer letra"<<endl;
	cout<<"Entre com os números:"<<endl;
	while(cin>>input){
		n+=input;
		++count;
		}
	double media=n/count;
	if(count==0){
		media=0;
		}
	cout<<"Média igual a "<<media<<endl;
	return 0;
}
