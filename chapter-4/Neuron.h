#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

class Neuron {
	public:
    	Neuron();

    	float weightedSum(std::vector<int> inputs);
    	int activationFunction(std::vector<int> inputs);

    	void train(std::vector<int> inputs, int target_output);
     protected:
     	std::vector<float> weights;
     	float threshold;
};

#endif