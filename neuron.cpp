#include "neuron.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Neuron::Neuron(std::vector<std::vector<double>> params, std::vector<int> names) : mInputs{ params }, mExpectedOutputs{ names }
{
	srand(static_cast<unsigned int>(time(0)));

	for (std::size_t i = 0; i < params.size(); ++i)
		mWeights.emplace_back(-1.0 + 2.0 * rand() / static_cast<float>(RAND_MAX));
}

void Neuron::UpdateWeights()
{
	for (std::size_t i = 0; i < mInputs.at(0).size(); ++i)
	{
		double sum_inputs = 0;
		for (std::size_t j = 0; j < mWeights.size(); ++j)
		{
			sum_inputs += mWeights.at(j) * mInputs.at(j).at(i);
		}
		int current_output = sum_inputs > 0.5 ? 1 : -1;
		int delta = mExpectedOutputs.at(i) - current_output;
		for (std::size_t j = 0; j < mWeights.size(); ++j)
		{
			mWeights.at(j) += 0.1 * mInputs.at(j).at(i) * delta;
		}
	}
}

void Neuron::CheckOutputs()
{
	for (std::size_t i = 0; i < mInputs.at(0).size(); ++i)
	{
		double sum_inputs = 0;
		for (std::size_t j = 0; j < mWeights.size(); ++j)
		{
			sum_inputs += mWeights.at(j) * mInputs.at(j).at(i);
		}
		int current_output = sum_inputs > 0.5 ? 1 : -1;
		if (current_output == 1)
			std::cout << "id: " << i + 1 << "\tKind of Iris: Iris-setosa" << std::endl;
		else if (current_output == -1)
			std::cout << "id: " << i + 1 << "\tKind of Iris: Iris-versicolor" << std::endl;
	}
}

