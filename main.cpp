#include "Neuron.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	Neuron n1(1);
	
	double I(0.0); //I = external current
	
	cout << "Specify an external current (I=[0,400 pA]) : ";
	cin >> I;
	
	double startTime(0.0);
	double stopTime(0.0);
	
	do{
		cout << endl;
		cout << "Choose the stop time: ";
		cin >> stopTime;
		cout << endl;
	} while (stopTime < startTime);
	
	ofstream out("simulator.txt");
	
	unsigned int i(0);
	for(double t(startTime); t<stopTime; t+=h){
		n1.update(t, I);
		if (out.fail()){
			cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
			<< "en écriture." << endl;
		} else {
				out << "A temps: " << n1.getSpikesTime()[i] << ", le potentiel de membrane est: " << n1.getPotential() << "." << endl;
				++i; 
		}		
		
	}
	
	
	return 0;
	
}
