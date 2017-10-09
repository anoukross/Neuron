#ifndef NEURON_HPP
#define NEURON_HPP
#include "Constants.hpp"
#include <vector>

class Neuron{
	private:
		double V; //Membrane potential 
		double V_th; //Valeur du potentiel qui cause un spike (Potential threshold) -> depend d'un neurone
		double R; //Membrane resistance -> depend d'un neurone
		unsigned int spikesNumber; //Number of spikes
		std::vector<double> spikesTime; // The times when the spikes occured
		double refractory_time;

		
	public:
		//Constructeur et destructeur
		Neuron(double potential=V_reset); //Initialisation par défaut à 0.0
		~Neuron();
		
		//Getters
		double getPotential() const;
		double getResistance() const;
		unsigned int getSpikesNumber() const;
		std::vector<double> getSpikesTime() const;
		
		bool isRefractory();
		
		//Update
		void update(double t, double I); //update the neuron state from time t to time t+T, where T is n*h (h pas de temps)	
										// I external current
};

#endif
