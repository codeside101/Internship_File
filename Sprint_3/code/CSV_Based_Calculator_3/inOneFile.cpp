#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> readMatricesFromCSV(const std::string &filePath)
{
    std::ifstream inputFile(filePath);
    std::vector<std::vector<double>> matrix1, matrix2;
    std::vector<std::vector<double>> *currentMatrix = &matrix1;
    std::string line;

    while (std::getline(inputFile, line))
    {
        if (line.empty())
        {
            currentMatrix = &matrix2;
            continue;
        }

        std::vector<double> row;
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ','))
        {
            row.push_back(std::stod(value));
        }
        currentMatrix->push_back(row);
    }

    return {matrix1, matrix2};
}

void writeMatricesToCSV(const std::string &filePath,
                        const std::vector<std::vector<double>> &additionResult,
                        const std::vector<std::vector<double>> &multiplicationResult)
{
    std::ofstream outputFile(filePath, std::ios::app);
    outputFile << "\nAddition Result:\n";
    for (const auto &row : additionResult)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            outputFile << row[i];
            if (i < row.size() - 1)
            {
                outputFile << ",";
            }
        }
        outputFile << std::endl;
    }
    outputFile << "\nMultiplication Result:\n";
    for (const auto &row : multiplicationResult)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            outputFile << row[i];
            if (i < row.size() - 1)
            {
                outputFile << ",";
            }
        }
        outputFile << std::endl;
    }
}

std::vector<std::vector<double>> addMatrices(const std::vector<std::vector<double>> &matrix1, const std::vector<std::vector<double>> &matrix2)
{
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix1[0].size()));

    for (size_t i = 0; i < matrix1.size(); ++i)
    {
        for (size_t j = 0; j < matrix1[0].size(); ++j)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<double>> multiplyMatrices(const std::vector<std::vector<double>> &matrix1, const std::vector<std::vector<double>> &matrix2)
{
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix2[0].size(), 0));

    for (size_t i = 0; i < matrix1.size(); ++i)
    {
        for (size_t j = 0; j < matrix2[0].size(); ++j)
        {
            for (size_t k = 0; k < matrix1[0].size(); ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main()
{
    std::string filePath = "D:\\codeside101\\july\\project04\\inOneFile.csv";

    auto matrices = readMatricesFromCSV(filePath);
    auto &matrix1 = matrices.first;
    auto &matrix2 = matrices.second;

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        std::cerr << "Matrices have different dimensions for addition." << std::endl;
        return 1;
    }

    if (matrix1[0].size() != matrix2.size())
    {
        std::cerr << "Matrices have incompatible dimensions for multiplication." << std::endl;
        return 1;
    }

    auto additionResult = addMatrices(matrix1, matrix2);

    auto multiplicationResult = multiplyMatrices(matrix1, matrix2);

    writeMatricesToCSV(filePath, additionResult, multiplicationResult);

    return 0;
}
