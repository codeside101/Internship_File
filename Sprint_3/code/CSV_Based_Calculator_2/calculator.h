#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>

class CSVCalculator {
public:
    CSVCalculator(const std::string& inputFilePath, const std::string& outputFilePath);
    
    bool readInputFile();
    void performCalculations();
    bool writeOutputFile();

private:
    std::string inputFilePath;
    std::string outputFilePath;
    std::vector<double> numbers;
    double num1, num2, sum, difference, product, quotient;
};

#endif // CALCULATOR_H
