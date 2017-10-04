#include "Neuron.hpp"
#include <cmath>

//Constructeur et destructeur
Neuron::Neuron(double potential)
:V(potential), V_th(20), R(tau/C), spikesNumber_(0.0), tempsPause_(0)
{
	spikesTime_.clear();
}
Neuron::~Neuron(){}
		
//Getters
double Neuron::getPotential() const{
	return V;
}
double Neuron::getResistance() const{
	return R;
}
unsigned int Neuron::getSpikesNumber() const{
	return spikesNumber_;
}
std::vector<double> Neuron::getSpikesTime() const{
	return spikesTime_;
}
		
//Update
void Neuron::update(double t, double I){
	if(tempsPause_ > 0.0){ //If neuron is refractory
		V=V_reset;
		tempsPause_-=h;
	}else{
		const double e(exp(-(h/tau)));
		double V_new(e*V+I*R*(1-e));
			
			if(V_new > V_th){
				spikesTime_.push_back(t);
				spikesNumber_+=1;
				tempsPause_=tau_ref;
				V_new=V_reset;
		}
		V=V_new; //modify neuron potential
	}	
}
