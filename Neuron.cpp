#include "Neuron.hpp"
#include <cmath>

//Constructeur et destructeur
Neuron::Neuron(double potential)
:V(potential), V_th(20), R(tau/C), spikesNumber_(0.0), break_time(0)
{
	spikesTime_.clear(); //To be sure that when we create a neuron it has got no spikes time 
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
	if(break_time > 0.0){ //If neuron is refractory -> neuron has spiked
		break_time-=h;//Decrementation of the break time
	}else{
		const double e(exp(-(h/tau)));
		double V_new(e*V+I*R*(1-e));
			
			if(V_new > V_th){
				spikesTime_.push_back(t); 
				spikesNumber_+=1;
				break_time=tau_ref; //Initialisation of the break time
				V_new=V_reset; //After a spike, a neuron gets back to its reset value
		}
		V=V_new; //modify neuron potential
	}	
}
