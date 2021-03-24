#pragma once

#include <vector>

class Neuron
{
public:
	Neuron(std::vector< std::vector<double> > params, std::vector<int> names);
	void UpdateWeights();
	void CheckOutputs();
private:
	std::vector<std::vector<double>> mInputs;
	std::vector<double> mWeights;
	std::vector<int> mExpectedOutputs;

};

