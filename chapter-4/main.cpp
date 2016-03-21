#include "Neuron.h"

int targetFunction(std::vector<int> inputs) {
	return inputs[0] | inputs[1];
}

int main(int argc, char **argv) {
  Neuron *neuron = new Neuron();

  std::vector<int> inputs;
  inputs.push_back(0);
  inputs.push_back(1);

  printf("%d %d = %d\n", inputs[0], inputs[1], neuron->activationFunction(inputs));
 
  int total_error = 0;

  printf("Training\n");	
  for(int epochs = 1; epochs <= 200; epochs++) {
  	printf("Epoch: %d) ", epochs);

  	//Randomly generate 1 or 0
  	inputs[0] = (rand() % 2);
  	inputs[1] = (rand() % 2);
  	
  	int target_output = targetFunction(inputs);

  	printf("Inputs: %d OR %d = %d\t", inputs[0], inputs[1], target_output);

  	neuron->train(inputs, target_output);
  	
  	int output = neuron->activationFunction(inputs);

  	printf("\tNeuron output: %d", output);

  	if(output == target_output) 
  		printf("\t[Y]");
  	else {
  		total_error++;
  		printf("\t\x1b[31m[X]\x1b[0m");
  	}

  	printf("\tError: %.2f\n", (total_error*100.0) / ((float)epochs));

  }

  return 0;
}