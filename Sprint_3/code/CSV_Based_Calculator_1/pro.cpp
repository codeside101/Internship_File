#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVCalculator {
public:
    CSVCalculator(const std::string& inputFilePath, const std::string& outputFilePath)
        : inputFilePath(inputFilePath), outputFilePath(outputFilePath) {}

    bool readInputFile() {
        std::ifstream inputFile(inputFilePath);
        if (!inputFile.is_open()) {
            std::cerr << "Failed to open input file: " << inputFilePath << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string value;
            while (std::getline(ss, value, ',')) {
                numbers.push_back(std::stod(value));
            }
        }
        inputFile.close();

        if (numbers.size() < 2) {
            std::cerr << "Not enough data in input file." << std::endl;
            return false;
        }

        return true;
    }

    void performCalculations() {
        if (numbers.size() >= 2) {
            num1 = numbers[0];
            num2 = numbers[1];
            sum = num1 + num2;
            difference = num1 - num2;
            product = num1 * num2;
            quotient = num1 / num2;
        }
    }

    bool writeOutputFile() {
        std::ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            std::cerr << "Failed to open output file: " << outputFilePath << std::endl;
            return false;
        }

        outputFile << "Sum," << sum << std::endl;
        outputFile << "Difference," << difference << std::endl;
        outputFile << "Product," << product << std::endl;
        outputFile << "Quotient," << quotient << std::endl;
        
        outputFile.close();
        return true;
    }

private:
    std::string inputFilePath;
    std::string outputFilePath;
    std::vector<double> numbers;
    double num1, num2, sum, difference, product, quotient;
};

int main() {
    std::string inputFilePath = "D:\\codeside101\\july\\project02\\input.csv"; 
    std::string outputFilePath = "D:\\codeside101\\july\\project02\\output.csv";

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
