#include "calculator.h"
#include <iostream>

int main() {
    std::string inputFilePath = "D:\\codeside101\\july\\project03\\intput.csv"; 
    std::string outputFilePath = "D:\\codeside101\\july\\project03\\output.csv"; 
    CSVCalculator calculator(inputFilePath, outputFilePath);

    if (!calculator.readInputFile()) {
        return 1;
    }

    calculator.performCalculations();

    if (!calculator.writeOutputFile()) {
        return 1;
    }

    return 0;
}
