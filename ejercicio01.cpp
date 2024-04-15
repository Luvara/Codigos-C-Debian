#include <iostream>

using namespace std;

int main(){

	cout<<"tabla de conversion de temperaturas"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"Fahrenheit\tCelsius"<<endl;

	for (int f = 0; f <=300; f+=20){
		double c = (5.0/9.0)*(f-32);
		cout<<f<<"\t\t"<<c<<endl;
	}	

	return 0;
}
