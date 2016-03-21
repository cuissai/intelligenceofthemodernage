#include "Neuron.h"

Neuron::Neuron() {
	threshold = 0.0;

	srand(time(NULL));
	for(int i = 0;i < 2; i++) {
		weights.push_back((rand() % 10) / 10.0);
	}
}

float Neuron::weightedSum(std::vector<int> inputs) {
	if(inputs.size() != weights.size()) {
		std::cout << "Wrong input size! " << std::endl;
		return 0;
	}

	float sum = 0.0;

	for(int i = 0; i < weights.size(); i++) {
		sum += inputs[i]*weights[i];
	}

	return sum;
}

int Neuron::activationFunction(std::vector<int> inputs) {
	int wsum = this->weightedSum(inputs);

	if(wsum > threshold)
		return 1;

	return 0;
}
