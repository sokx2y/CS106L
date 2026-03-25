#include <iostream>
#include <utility>
#include <string>
#include <cmath>

std::pair<bool, std::pair<double,double>> solveQuadradic_1(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return {false, {0.0, 0.0}};
    }

    double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
    return {true, {root1, root2}};
}

using zeros = std::pair<double,double>;
using solution = std::pair<bool, zeros>;

solution solveQuadradic_2(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return {false, {0.0, 0.0}};
    }

    double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
    return {true, {root1, root2}};
}


int main(){
    double a = 1, b=-3, c =2;
    std::pair<bool, std::pair<double,double>> result;
    result = solveQuadradic_1(a,b,c);
    std::cout << "result = " << result.first << ","<< result.second.first << "," << result.second.second<< std::endl;
    
    auto solution = solveQuadradic_2(a,b,c);
    std::cout << "solution = " << solution.first << ","<< solution.second.first << "," << solution.second.second<< std::endl;
    
    return 0;
}