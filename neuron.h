#pragma once

#include <vector>

class Neuron
{
public:
	Neuron(std::vector< std::vector<double> > params, std::vector<int> names);
	void UpdateWeights();
	void CheckOutputs(std::vector< std::vector<double> > test);
	void TotalError();
	double LastError();
private:
	std::vector<std::vector<double>> mInputs;
	std::vector<double> mWeights;
	std::vector<double> mShifts;
	std::vector<int> mExpectedOutputs;
	std::vector<int> mTotalError;
};

