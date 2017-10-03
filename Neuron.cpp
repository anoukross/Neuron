#include "Neuron.hpp"
#include <cmath>

//Constructeur et destructeur
Neuron::Neuron(double potential)
:potential_(potential), potentialTh_(0.0), resistance_(tau/capacite), spikesNumber_(0.0), tempsPause_(tauRef)
{
	spikesTime_.clear();
}
Neuron::~Neuron(){}
		
//Getters
double Neuron::getPotential() const{
	return potential_;
}
double Neuron::getResistance() const{
	return resistance_;
}
unsigned int Neuron::getSpikesNumber() const{
	return spikesNumber_;
}
std::vector<double> Neuron::getSpikesTime() const{
	return spikesTime_;
}
		
//Update
void Neuron::update(double t, double I){
	if(tempsPause_< tauRef){ //If neuron is refractory
		potential_=0;
		tempsPause_-=h;
	}else{
		const double exphtau(exp(-(h/tau)));
		double newPotential(exphtau*potential_+I*resistance_*(1-exphtau));
		potential_= newPotential; //modify neuron potential
			
			if(potential_ > potentialTh_){
				spikesTime_.push_back(t);
				spikesNumber_+=1;
		}
	}	
}
