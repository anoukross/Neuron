#ifndef NEURON_HPP
#define NEURON_HPP
#include "Constants.hpp"
#include <vector>

class Neuron{
	private:
		double potential_; //Membrane potential
		double potentialTh_; //Valeur du potentiel qui cause un spike (Potential threshold)
		double resistance_; //Membrane resistance
		unsigned int spikesNumber_; //Number of spikes
		std::vector<double> spikesTime_; // The times when the spikes occured
		double tempsPause_;

		
	public:
		//Constructeur et destructeur
		Neuron(double potential=0.0); //Initialisation par défaut à 0.0
		~Neuron();
		
		//Getters
		double getPotential() const;
		double getResistance() const;
		unsigned int getSpikesNumber() const;
		std::vector<double> getSpikesTime() const;
		
		//Update
		void update(double t, double I); //update the neuron state from time t to time t+T, where T is n*h (h pas de temps)	
										// I external current
};

#endif
