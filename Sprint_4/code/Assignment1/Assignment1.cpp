#include <iostream>
#include <cmath>


double calPerDistance2D(double x1, double y1, double x2, double y2, double x3, double y3) {
    double A = y2 - y1;
    double B = x1 - x2;
    double C = x2 * y1 - x1 * y2;
    double distance = std::abs(A * x3 + B * y3 + C) / std::sqrt(A * A + B * B);
    std::cout<<"The equation of line in 2D is Ax+By+C=0 where (A,B,C) is ";
    std::cout<<"("<<A<<","<<B<<","<<C<<")"<<std::endl;
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

    double crossMag = std::sqrt(crossX * crossX + crossY * crossY + crossZ * crossZ);
    double ABMag = std::sqrt(ABx * ABx + ABy * ABy + ABz * ABz);

    double distance = crossMag / ABMag;
    std::cout<<"The equation of line in 3D in vector form is r=ro+tv where (<ro>,<v>) is"<<"(<"<<x1<<" "<<y1<<" "<<z1<<">,"<<"<"<<ABx<<" "<<ABy<<" "<<ABz<<">)"<<std::endl;
    return distance;
}

int main() {
    
    double x1 = 0, y1 = 0;
    double x2 = 5, y2 = 0;
    double x3 =-6, y3 = -3;
    double distance2D = calPerDistance2D(x1, y1, x2, y2, x3, y3);
    std::cout << "Perpendicular distance in 2D: " << distance2D << std::endl;

 
    double x1_3D = 0, y1_3D = 0, z1_3D = 7;
    double x2_3D = 5, y2_3D = 0, z2_3D = 7;
    double x3_3D = 6, y3_3D = 102.35983, z3_3D = 7;
    double distance3D = calPerDistance3D(x1_3D, y1_3D, z1_3D, x2_3D, y2_3D, z2_3D, x3_3D, y3_3D, z3_3D);
    std::cout << "Perpendicular distance in 3D: " << distance3D << std::endl;

    return 0;
}
