#include "Neuron.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	Neuron n1;
	
	double I(0); //I = external current
	
	cout << "Specify an external current (I=[0,400 pA]) : ";
	cin >> I;
	cout << endl;
	
	double startTime(0.0);
	double stopTime(0.0);
	

	cout << "Choose the stop time: ";
	cin >> stopTime;
	cout << endl;
	
	
	ofstream out("simulator.txt");
	int steps_number(stopTime/n1.h); //Division by h 
	
	for(double t(startTime/n1.h); t<steps_number; t+=1){
		if (out.fail()){
			cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
			<< "en écriture." << endl;
		} else {
			out << "A temps: " << t*n1.h << " ms, le potentiel de membrane est: " << n1.getPotential() << "." << endl;
				
				

		}	
		n1.update(I);	
		
	}
	
	
	return 0;
	
}
