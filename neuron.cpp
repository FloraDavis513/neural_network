#include "neuron.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Neuron::Neuron(std::vector<std::vector<double>> params, std::vector<int> names) : mInputs{ params }, mExpectedOutputs{ names }
{
	srand(static_cast<unsigned int>(time(0)));
	mShifts.reserve(params.size());
	for (std::size_t i = 0; i < params.size(); ++i)
	{
		mWeights.emplace_back(-3.0 + 6.0 * rand() / static_cast<float>(RAND_MAX));
		mShifts.emplace_back(0);
	}
		
}

void Neuron::UpdateWeights()
{
	for (auto& el : mShifts)
		el = 0;
	for (std::size_t i = 0; i < mInputs.at(0).size(); ++i)
	{
		double sum_inputs = 0;
		for (std::size_t j = 0; j < mWeights.size(); ++j)
		{
			sum_inputs += mWeights.at(j) * mInputs.at(j).at(i);
		}
		double sigma = 1 / (1 + exp(-sum_inputs));
		int current_output = sigma > 0.5 ? 1 : -1;
		int delta = mExpectedOutputs.at(i) - current_output;
		for (std::size_t j = 0; j < mWeights.size(); ++j)
		{
			// mWeights.at(j) += 0.1 * mInputs.at(j).at(i) * delta;
			mShifts.at(j) += 0.1 * mInputs.at(j).at(i) * delta;
		}
		if (i % 23 == 0)
		{
			for (std::size_t j = 0; j < mWeights.size(); ++j)
			{
				mWeights.at(j) += mShifts.at(j);
			}
		}
	}
}

void Neuron::CheckOutputs(std::vector< std::vector<double> > test)
{
	int sum_error = 0;
	for (std::size_t i = 0; i < test.at(0).size(); ++i)
	{
		double sum_inputs = 0;
		for (std::size_t j = 0; j < mWeights.size(); ++j)
		{
			sum_inputs += mWeights.at(j) * test.at(j).at(i);
		}
		double sigma = 1 / (1 + exp(-sum_inputs));
		int current_output = sigma > 0.5 ? 1 : -1;
		if (current_output == 1)
		{
			// std::cout << "id: " << i + 1 << "\tKind of Iris: Iris-setosa" << std::endl;
			if (i > 13)
				sum_error++;
		}
		else if (current_output == -1)
		{
			// std::cout << "id: " << i + 1 << "\tKind of Iris: Iris-versicolor" << std::endl;
			if (i < 13)
				sum_error++;
		}
	}
	mTotalError.push_back((1.0 - (sum_error / 30.0))*100);
}

void Neuron::TotalError()
{
	std::cout << "[";
	for (const auto& error : mTotalError)
	{
		std::cout << error << ",";
	}
	std::cout << "]";
}

double Neuron::LastError()
{
	return mTotalError.at(mTotalError.size() - 1);
}

