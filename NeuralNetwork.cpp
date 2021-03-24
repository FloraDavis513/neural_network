#include "ParseCSV.cpp"
#include "neuron.h"

int main()
{
    std::vector<double> lengths; 
    std::vector<double> widths; 
    std::vector<int> names;
    ParseCSV(lengths, widths, names);

    std::vector< std::vector<double> > params; // таблица, где каждая строка - входной параметр в нейрон
    params.push_back(lengths);
    params.push_back(widths);

    Neuron neuron{ params, names };

    for (auto gen = 0; gen < 1000; ++gen)
    {
        neuron.UpdateWeights();
    }
    neuron.CheckOutputs();
}

