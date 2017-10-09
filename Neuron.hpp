#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>

class Neuron{
	private:
	
		//Constantes de classe
		const double tau=20; //tau = R*C , [ms]
		const double C=1; // capacity 1 pF=10⁻12 Farad
		const double R=tau/C; //Membrane resistance
		const double tau_ref=2; //tau refractory 2 ms
		const double Erepos=10; //10mV
		const double V_reset=0; // mV Membrane potential during the refractory time
		const double V_th=20; //Valeur du potentiel qui cause un spike (Potential threshold)
		const int step=1; //remplace le pas de temps h
	

	
		//atrributs
		double V; //Membrane potential 
		unsigned int spikesNumber; //Number of spikes
		std::vector<double> spikesTime; // The times when the spikes occured
		double refractory_time;
		int clock;

		
	public:
	
		//Constante de classe publique
		const double h=0.1; //pas de temps h = 0.1 ms
		
		//Constructeur et destructeur
		Neuron(double potential=0.0); //Initialisation par défaut à 0.0
		~Neuron();
		
		//Getters
		double getPotential() const;
		double getResistance() const;
		unsigned int getSpikesNumber() const;
		std::vector<double> getSpikesTime() const;
		
		bool isRefractory();
		
		//Update
		void update(double I); //update the neuron state from time t to time t+T, where T is n*h (h pas de temps)	
										// I external current
};

#endif
