#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>

double calPerDistance2D(double x1, double y1, double x2, double y2, double x3, double y3) {
    double A = y2 - y1;
    double B = x1 - x2;
    double C = x2 * y1 - x1 * y2;
    double distance = std::abs(A * x3 + B * y3 + C) / std::sqrt(A * A + B * B);
    return distance;
}

double calPerDistance3D(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
    double ABx = x2 - x1;
    double ABy = y2 - y1;
    double ABz = z2 - z1;
    double ACx = x3 - x1;
    double ACy = y3 - y1;
    double ACz = z3 - z1;

    double crossX = ABy * ACz - ABz * ACy;
    double crossY = ABz * ACx - ABx * ACz;
    double crossZ = ABx * ACy - ABy * ACx;

    double crossMagnitude = std::sqrt(crossX * crossX + crossY * crossY + crossZ * crossZ);
    double ABMagnitude = std::sqrt(ABx * ABx + ABy * ABy + ABz * ABz);

    double distance = crossMagnitude / ABMagnitude;
    return distance;
}

int main() {
    std::string inputFileName = "D:\\codeside101\\july\\Assignment2\\input_points.csv";
    std::string outputFileName = "D:\\codeside101\\july\\Assignment2\\output_distances.csv";
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<std::string>> data;
    std::vector<double> distances;


    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> row;

        while (std::getline(ss, item, ',')) {
            row.push_back(item);
        }

        if (row.size() == 6) {
            double x1 = std::stod(row[0]);
            double y1 = std::stod(row[1]);
            double x2 = std::stod(row[2]);
            double y2 = std::stod(row[3]);
            double x3 = std::stod(row[4]);
            double y3 = std::stod(row[5]);

            double distance = calPerDistance2D(x1, y1, x2, y2, x3, y3);
            distances.push_back(distance);
        } else if (row.size() == 9) {
            double x1 = std::stod(row[0]);
            double y1 = std::stod(row[1]);
            double z1 = std::stod(row[2]);
            double x2 = std::stod(row[3]);
            double y2 = std::stod(row[4]);
            double z2 = std::stod(row[5]);
            double x3 = std::stod(row[6]);
            double y3 = std::stod(row[7]);
            double z3 = std::stod(row[8]);

            double distance = calPerDistance3D(x1, y1, z1, x2, y2, z2, x3, y3, z3);
            distances.push_back(distance);
        }

        data.push_back(row);
    }

    inputFile.close();

   
    for (int i = 0; i < distances.size(); ++i) {
        if (data[i].size() == 6) {
            outputFile << "2D Distance: "<<"," << distances[i] << std::endl;
        } else if (data[i].size() == 9) {
            outputFile << "3D Distance: "<<"," << distances[i] << std::endl;
        }
    }

    outputFile.close();

    std::cout << "Perpendicular distances have been calculated and written to " << outputFileName << std::endl;

    return 0;
}
