#include "Neuron.h"

int main(int argc, char **argv) { 
	Neuron *neuron = new Neuron();
	
	std::vector<int> inputs; 
	inputs.push_back(0); 
	inputs.push_back(1);

    std::cout << inputs[0] << " " << inputs[1] << " " 
    		  << neuron->activationFunction(inputs) 
    		  << std::endl;

    		  
	getchar(); 
	return 0;
}