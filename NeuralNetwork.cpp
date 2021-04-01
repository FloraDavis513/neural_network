#include "ParseCSV.cpp"
#include "neuron.h"

int main()
{
    std::vector<double> lengths; 
    std::vector<double> widths; 
    std::vector<int> names;
    ParseCSV(lengths, widths, names);

    std::vector<double> train_lengths;
    std::vector<double> train_widths;
    std::vector<double> test_lengths;
    std::vector<double> test_widths;

    for (std::size_t i = 0; i < lengths.size(); ++i)
    {
        if ((i > 34 && i < 49) || i > 84)
        {
            test_lengths.push_back(lengths.at(i));
            test_widths.push_back(widths.at(i));
        }
        else
        {
            train_lengths.push_back(lengths.at(i));
            train_widths.push_back(widths.at(i));
        }
    }

    std::vector< std::vector<double> > params; // таблица, где каждая строка - входной параметр в нейрон
    params.push_back(train_lengths);
    params.push_back(train_widths);

    std::vector< std::vector<double> > test; // таблица, где каждая строка - входной параметр в нейрон
    test.push_back(test_lengths);
    test.push_back(test_widths);

    Neuron neuron{ params, names };

    for (auto gen = 0; gen < 200; ++gen)
    {
        neuron.UpdateWeights();
        neuron.CheckOutputs(test);
        if (neuron.LastError() > 95)
            break;
    }
    neuron.TotalError();

    
}

