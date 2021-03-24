#include <vector>
#include <string>
#include <fstream>

void ParseCSV(std::vector<double>& lengths, std::vector<double>& widths, std::vector<int>& names)
{
    std::ifstream input_data("Iris.csv");
    for(std::size_t i = 0; i < 101; ++i)
    {
        std::string strInput;
        input_data >> strInput;

        // Заголовки игнорируем
        if (i == 0)
            continue;

        // id игнорируем
        std::size_t pos = strInput.find(",");
        strInput.replace(0, pos + 1, "");

        // Достаем длину
        pos = strInput.find(",");
        std::string length = strInput.substr(0, pos);
        lengths.emplace_back(std::stod(length));
        strInput.replace(0, pos + 1, "");

        // Достаем ширину
        pos = strInput.find(",");
        std::string width = strInput.substr(0, pos);
        widths.emplace_back(std::stod(width));

        // Достаем название
        pos = strInput.rfind(",");
        std::string name = strInput.substr(pos + 1, strInput.length());
        name == "Iris-setosa" ? names.emplace_back(1) : names.emplace_back(-1);
    }
    
}